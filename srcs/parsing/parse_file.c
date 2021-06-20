#include "master.h"

static void	check_is_map_closed(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_h)
	{
		if (y == 0 || y == data->map_h - 1)
		{
			x = 1;
			while (data->map[y][x] == '1')
				x++;
			if (data->map[y][x])
				error("Map is not closed", data);
		}
		if (data->map[y][0] != '1' || data->map[y][data->map_w - 1] != '1')
			error("Map is not closed", data);
		y++;
	}
}

static void	check_line_char(char c, int i, t_data *data)
{
	if (c == 'C')
		data->nb_c++;
	if (c == 'E')
	{
		if (data->e_x)
			error("More than one exit in map", data);
		data->e_x = i;
		data->e_y = data->map_h - 1;
	}
	if (c == 'F')
		foe_add(i, data->map_h - 1, data);
	if (c == 'P')
	{
		if (data->plr.x)
			error("More than one player in map", data);
		data->plr.x = i;
		data->plr.y = data->map_h - 1;
	}
}

static void	check_line_chars(char *line, t_data *data)
{
	int		i;
	char	*chars;
	int		ch_i;

	i = 0;
	chars = "01CEFP";
	while (line[i])
	{
		ch_i = 0;
		while (chars[ch_i] && chars[ch_i] != line[i])
			ch_i++;
		if (!(chars[ch_i]))
			error("A forbidden character has been found in the map", data);
		check_line_char(line[i], i, data);
		i++;
	}
}

static void	check_line(char *line, int gnl_ret, t_data *data)
{
	int	len;

	if (gnl_ret == -1)
		error("Unable to read the map file", data);
	len = ft_strlen(line);
	if (!data->map_w)
		data->map_w = len;
	if (!len && gnl_ret)
	{
		free(line);
		error("Empty line found in map", data);
	}
	if (len)
	{
		data->map_h++;
		data->map = add_str_to_tab(line, data->map);
		check_line_chars(line, data);
		if (data->map_w != len)
			error("Map is not rectangular", data);
	}
	else
		free(line);
}

void	parse_file(t_data *data)
{
	char	*line;
	int		gnl_ret;

	printf("Parsing file...\n");
	gnl_ret = 1;
	while (gnl_ret == 1)
	{
		gnl_ret = get_next_line(data->fd, &line);
		check_line(line, gnl_ret, data);
	}
	if (data->map == NULL)
		error("Map file is empty", data);
	check_is_map_closed(data);
	if (!data->plr.x)
		error("No player in map", data);
	if (!data->e_x)
		error("No exit in map", data);
	if (!data->nb_c)
		error("No collectible in map", data);
	printf("Map is %dx%d.\n", data->map_w, data->map_h);
}
