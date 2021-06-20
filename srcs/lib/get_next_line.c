#include "master.h"

static unsigned long	allocation_size(t_gnl_data *data)
{
	unsigned long	size;
	int				i;

	size = 1;
	i = data->i;
	while (data->buf[i] != '\n' && i < data->n)
	{
		i++;
		size++;
	}
	return (size);
}

static int	extend_str(char **str, t_gnl_data *data, unsigned long size)
{
	char			*new;
	unsigned long	i;

	if (!data->n)
		return (0);
	i = 0;
	new = malloc(size + allocation_size(data));
	if (new == NULL)
		return (1);
	while (i < size)
	{
		new[i] = (*str)[i];
		i++;
	}
	free(*str);
	*str = new;
	return (0);
}

static int	start(char **l, unsigned long l_i, t_gnl_data *data)
{
	if (*l == NULL)
	{
		*l = malloc(allocation_size(data));
		if (*l == NULL)
			return (-1);
	}
	if (data->i == data->n)
	{
		data->i = 0;
		data->n = read(data->fd, data->buf, BUFFER_SIZE);
		if (data->n == -1 || extend_str(l, data, l_i))
		{
			free(*l);
			return (-1);
		}
	}
	return (0);
}

static int	fill_line(t_gnl_data *data, char **line)
{
	unsigned long	l_i;
	char			*l;

	l_i = 0;
	l = 0;
	while (1)
	{
		if (start(&l, l_i, data) == -1)
			return (-1);
		while (data->buf[data->i] != '\n' && data->i < data->n)
			l[l_i++] = data->buf[data->i++];
		if (data->buf[data->i] == '\n'
			|| (data->i == data->n && data->n < BUFFER_SIZE))
		{
			l[l_i] = 0;
			*line = l;
			if (data->i++ == data->n)
				return (0);
			return (1);
		}
	}
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_data	*data = NULL;
	int					ret;

	if (fd < 0)
		return (-1);
	if (data == NULL)
	{
		data = malloc(sizeof(*data));
		if (data == NULL)
			return (-1);
		data->i = 0;
		data->n = 0;
		data->fd = fd;
	}
	ret = fill_line(data, line);
	if (ret != 1)
	{
		free(data);
		data = NULL;
	}
	return (ret);
}
