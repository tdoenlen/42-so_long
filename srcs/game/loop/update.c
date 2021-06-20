#include "master.h"

static void	update_anims(t_data *data)
{
	update_anim(&(data->anims.f.d), data);
	update_anim(&(data->anims.f.l), data);
	update_anim(&(data->anims.f.r), data);
	update_anim(&(data->anims.f.u), data);
	update_anim(&(data->anims.p.d), data);
	update_anim(&(data->anims.p.l), data);
	update_anim(&(data->anims.p.r), data);
	update_anim(&(data->anims.p.u), data);
}

static void	update_delta(t_data *data)
{
	static struct timeval	last_time = {0, 0};
	struct timeval			time;

	gettimeofday(&time, NULL);
	if (last_time.tv_sec == 0)
		time.tv_usec = 0;
	data->delta = ((double)time.tv_usec - (double)last_time.tv_usec) / 1e6;
	if (data->delta < 0.)
		data->delta = 0.;
	last_time = time;
}

int	update(t_data *data)
{
	update_delta(data);
	update_anims(data);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, data->win);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->bg_img.ptr);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->win_img.ptr);
	update_bg_img(data);
	update_win_img(data);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img.ptr, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->win_img.ptr, 0, 0);
	mlx_string_put(data->mlx, data->win, 16, 32, 0x0, data->nb_mov_str);
	if (!(data->plr.x))
		mlx_string_put(data->mlx, data->win,
			data->w / 2 - 40, data->h / 2, 0x0, "VICTORY");
	else if (!(data->plr.y))
		mlx_string_put(data->mlx, data->win,
			data->w / 2 - 48, data->h / 2, 0x0, "GAME OVER");
	return (0);
}
