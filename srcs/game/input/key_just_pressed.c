#include "master.h"

static void	modify_plr_coords(int x, int y, t_data *data)
{
	data->plr.x += x;
	data->plr.y += y;
	data->nb_mov++;
	free(data->nb_mov_str);
	data->nb_mov_str = ft_itoa(data->nb_mov);
	if (data->nb_mov_str == NULL)
		error("nb_mov_str allocation failed", data);
}

static void	move_plr(int x, int y, t_data *data)
{
	if (x == -1)
		data->plr.anim = &(data->anims.p.l);
	else if (x == 1)
		data->plr.anim = &(data->anims.p.r);
	else if (y == -1)
		data->plr.anim = &(data->anims.p.u);
	else if (y == 1)
		data->plr.anim = &(data->anims.p.d);
	if (data->map[data->plr.y + y][data->plr.x + x] != '1')
	{
		modify_plr_coords(x, y, data);
		if (data->foes && data->nb_mov % 2)
			move_foes(data);
		check_is_plr_colliding_foe(data);
	}
}

static void	update_game_data(int key, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == KEY_A)
		x--;
	else if (key == KEY_D)
		x++;
	else if (key == KEY_W)
		y--;
	else if (key == KEY_S)
		y++;
	if (x || y || key == KEY_Q)
		move_plr(x, y, data);
}

int	key_just_pressed(int key, t_data *data)
{
	if (key == KEY_ESC)
		quit(data);
	else if (key == KEY_E)
		reset_game(data);
	else if (data->plr.x && data->plr.y)
		update_game_data(key, data);
	return (0);
}
