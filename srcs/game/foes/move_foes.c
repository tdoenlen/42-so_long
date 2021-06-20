#include "master.h"

static void	rm_duplicate_foes(t_data *data)
{
	t_foe	*foe;
	t_foe	*other_foe;
	t_foe	*prev_foe;

	foe = data->foes;
	while (foe->next)
	{
		prev_foe = foe;
		other_foe = foe->next;
		while (other_foe)
		{
			if (other_foe->x == foe->x && other_foe->y == foe->y)
			{
				foe_rm(other_foe, data);
				other_foe = prev_foe;
			}
			else
				prev_foe = prev_foe->next;
			other_foe = other_foe->next;
		}
		if (foe->next)
			foe = foe->next;
	}
}

static void	set_foe_anim(t_foe *foe, int x_mov, int y_mov, t_data *data)
{
	if (x_mov == -1)
		foe->anim = &(data->anims.f.l);
	else if (x_mov == 1)
		foe->anim = &(data->anims.f.r);
	else if (y_mov == -1)
		foe->anim = &(data->anims.f.u);
	else if (y_mov == 1)
		foe->anim = &(data->anims.f.d);
}

static void	move_foe(t_foe *foe, t_data *data)
{
	int		x_mov;
	int		y_mov;
	t_foe	*new_foe;

	x_mov = get_dir(foe->x, data->plr.x);
	y_mov = get_dir(foe->y, data->plr.y);
	set_foe_anim(foe, x_mov, y_mov, data);
	if (data->map[foe->y + y_mov][foe->x] == '1')
		y_mov = 0;
	if (data->map[foe->y][foe->x + x_mov] == '1')
		x_mov = 0;
	if (x_mov && y_mov)
	{
		new_foe = foe_add(foe->x, foe->y + y_mov, data);
		if (y_mov == -1)
			new_foe->anim = &(data->anims.f.u);
		y_mov = 0;
	}
	foe->x += x_mov;
	foe->y += y_mov;
	set_foe_anim(foe, x_mov, y_mov, data);
}

void	move_foes(t_data *data)
{
	t_foe	*last_foe;
	t_foe	*cur_foe;

	last_foe = data->foes;
	while (last_foe->next)
		last_foe = last_foe->next;
	cur_foe = data->foes;
	while (cur_foe != last_foe->next)
	{
		move_foe(cur_foe, data);
		cur_foe = cur_foe->next;
	}
	rm_duplicate_foes(data);
}
