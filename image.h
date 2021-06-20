#ifndef IMAGE_H
# define IMAGE_H

# include "data.h"

void	img_pixel_put_t(t_img *img, int clr, int x, int y);
void	img_pixel_put(t_img *img, int clr, int x, int y);
int		get_img_pixel(t_img *img, int x, int y, int ratio);

t_img	new_img(int w, int h, t_data *data);
t_img	new_img_from_png(char *path, t_data *data);
t_img	new_img_from_xpm(char *path, t_data *data);

#endif
