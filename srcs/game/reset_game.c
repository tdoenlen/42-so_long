#include "master.h"

static void	reset_game_check_map_char(int x, int y, t_data *data)
{
	if (data->map[y][x] == 'c' || data->map[y][x] == 'C')
	{
		data->nb_c++;
		data->map[y][x] = 'C';
	}
	if (data->map[y][x] == 'F')
		foe_add(x, y, data);
	if (data->map[y][x] == 'P')
	{
		data->plr.x = x;
		data->plr.y = y;
	}
	if (data->map[y][x] == 'e')
		data->map[y][x] = 'E';
}

static void	reset_game_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			reset_game_check_map_char(x, y, data);
			x++;
		}
		y++;
	}
}

static void	reset_game_data(t_data *data)
{
	data->nb_c = 0;
	free(data->nb_mov_str);
	data->nb_mov_str = ft_itoa(0);
	if (data->nb_mov_str == NULL)
		error("nb_mov_str allocation failed", data);
	data->nb_mov = 0;
	data->plr.anim = &(data->anims.p.d);
	data->anims.e.cur_f = data->anims.e.f_tab;
	data->anims.e.cur_t = 0.;
	foe_clr(data);
	reset_game_map(data);
}

void	reset_game(t_data *data)
{
	printf("Reset game...\n");
	reset_game_data(data);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, data->win);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->bg_img.ptr);
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, data->win_img.ptr);
	fill_bg(data);
	fill_win_img_with_clr(0xFF000000, data);
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, data->win);
	printf("Game reset!\n\n");
}
