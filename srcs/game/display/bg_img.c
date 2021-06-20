#include "master.h"

void	update_bg_img(t_data *data)
{
	int	end_anim;

	data->dest_img = &(data->bg_img);
	if (data->map[data->plr.y][data->plr.x] == 'C')
	{
		data->map[data->plr.y][data->plr.x] = 'c';
		put_ttr_to_dest_tile(&(data->ttrs.col1),
			data->plr.x, data->plr.y, data);
		data->nb_c--;
	}
	if (!(data->nb_c))
	{
		end_anim = update_anim(&(data->anims.e), data);
		if (end_anim)
		{
			data->nb_c--;
			data->map[data->e_y][data->e_x] = 'e';
			put_ttr_to_dest_tile(&(data->ttrs.exit1),
				data->e_x, data->e_y, data);
		}
		else
			put_ttr_to_dest_tile(data->anims.e.cur_f,
				data->e_x, data->e_y, data);
	}
}
