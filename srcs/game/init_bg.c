#include "master.h"

static t_img	*get_wall_ttr_from_map(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'C')
		return (&(data->ttrs.col0));
	if (data->map[y][x] == 'E')
		return (&(data->ttrs.exit0));
	if (data->map[y][x] != '1')
		return (NULL);
	if (y > 0 && data->map[y - 1][x] == '1'
		&& y < data->map_h - 1 && data->map[y + 1][x] == '1')
		return (&(data->ttrs.bg.o_trees));
	if (y > 0 && data->map[y - 1][x] == '1')
		return (&(data->ttrs.bg.b_tree));
	if (y < data->map_h - 1 && data->map[y + 1][x] == '1')
		return (&(data->ttrs.bg.t_tree));
	return (&(data->ttrs.bg.bush));
}

void	fill_bg(t_data *data)
{
	int		x;
	int		y;
	t_img	*ttr;

	printf("Filling background...\n");
	data->dest_img = &(data->bg_img);
	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			put_ttr_to_dest_tile(&(data->ttrs.bg.grass), x, y, data);
			ttr = get_wall_ttr_from_map(x, y, data);
			if (ttr)
				put_ttr_to_dest_tile(ttr, x, y, data);
			x++;
		}
		y++;
	}
}
