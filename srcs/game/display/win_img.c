#include "master.h"

void	fill_win_img_with_clr(int clr, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			img_pixel_put_t(&(data->win_img), clr, x, y);
			x++;
		}
		y++;
	}
}

static void	put_foes_ttr(t_data *data)
{
	t_foe	*foe;

	foe = data->foes;
	while (foe)
	{
		put_ttr_to_dest_tile(foe->anim->cur_f,
			foe->x, foe->y, data);
		foe = foe->next;
	}
}

void	update_win_img(t_data *data)
{
	if (data->map[data->plr.y][data->plr.x] == 'e')
		data->plr.x = 0;
	if (data->plr.x && data->plr.y)
	{
		fill_win_img_with_clr(0xFF000000, data);
		data->dest_img = &(data->win_img);
		put_ttr_to_dest_tile(data->plr.anim->cur_f,
			data->plr.x, data->plr.y, data);
		if (data->foes)
			put_foes_ttr(data);
	}
	else
		fill_win_img_with_clr(0x77777777, data);
}
