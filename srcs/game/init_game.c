#include "master.h"

static void	hook_func(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	mlx_loop_hook(data->mlx, update, data);
	mlx_hook(data->win, KEY_PRESS, 0, key_just_pressed, data);
	mlx_hook(data->win, DESTROY_NOTIFY, 0, quit, data);
}

static int	calc_ratio(int n)
{
	int	ret;

	if (!n)
		return (0);
	ret = 1;
	if (n < 0)
		ret = -1;
	while (n)
	{
		if (n < 0)
			n++;
		else
			n--;
		ret *= 2;
	}
	return (ret);
}

static void	init_win(t_data *data)
{
	int	max_w;
	int	max_h;

	mlx_get_screen_size(data->mlx, &max_w, &max_h);
	data->tile_dim = TILE_DIM * 4;
	data->ratio = 2;
	data->w = data->map_w * data->tile_dim;
	data->h = data->map_h * data->tile_dim;
	while (data->w > max_w || data->h > max_h)
	{
		data->w /= 2;
		data->h /= 2;
		data->tile_dim /= 2;
		data->ratio--;
	}
	data->ratio = calc_ratio(data->ratio);
	printf("Creating %dx%d window...\n", data->w, data->h);
	data->win = mlx_new_window(data->mlx, data->w, data->h, "so_long");
	if (data->win == NULL)
		error("Failed to create the window", data);
	data->bg_img = new_img(data->w, data->h, data);
	data->win_img = new_img(data->w, data->h, data);
}

void	init_game(t_data *data)
{
	load_ttrs(data);
	init_win(data);
	fill_bg(data);
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img.ptr, 0, 0);
	fill_win_img_with_clr(0xFF000000, data);
	mlx_put_image_to_window(data->mlx, data->win, data->win_img.ptr, 0, 0);
	hook_func(data);
}
