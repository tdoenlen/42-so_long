#include "master.h"

void	format_img(t_img *img, int w, int h)
{
	img->w = w;
	img->h = h;
	img->addr = mlx_get_data_addr(img->ptr, &(img->p), &(img->l), &(img->e));
	img->p /= 8;
}

t_img	new_img(int w, int h, t_data *data)
{
	t_img	img;

	printf("Making new %dx%d image...\n", w, h);
	img.ptr = mlx_new_image(data->mlx, w, h);
	if (img.ptr == NULL)
		error("Failed to create new image", data);
	format_img(&img, w, h);
	return (img);
}

t_img	new_img_from_png(char *path, t_data *data)
{
	t_img	img;
	int		w;
	int		h;

	printf("Loading '%s'...\n", path);
	img.ptr = mlx_png_file_to_image(data->mlx, path, &w, &h);
	if (img.ptr == NULL)
		error("Failed to convert a png file to an image", data);
	format_img(&img, w, h);
	return (img);
}

t_img	new_img_from_xpm(char *path, t_data *data)
{
	t_img	img;
	int		w;
	int		h;

	printf("Loading '%s'...\n", path);
	img.ptr = mlx_xpm_file_to_image(data->mlx, path, &w, &h);
	if (img.ptr == NULL)
		error("Failed to convert a xpm file to an image", data);
	format_img(&img, w, h);
	return (img);
}
