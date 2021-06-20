#include "master.h"

void	put_ttr_to_dest_tile(t_img *ttr, int x_i, int y_i, t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->tile_dim)
	{
		x = 0;
		while (x < data->tile_dim)
		{
			img_pixel_put(data->dest_img,
				get_img_pixel(ttr, x, y, data->ratio),
				x + x_i * data->tile_dim, y + y_i * data->tile_dim);
			x++;
		}
		y++;
	}
}
