#include "master.h"

void	img_pixel_put_t(t_img *img, int clr, int x, int y)
{
	if (x >= img->w || y >= img->h)
		printf("WARNING: putting pixel out of image: x%+d, y%+d\n",
			x - img->w + 1, y - img->h + 1);
	if (x >= img->w)
		x = img->w - 1;
	if (y >= img->h)
		y = img->h - 1;
	*((unsigned int *)(img->addr + y * img->l + x * img->p)) = clr;
}

void	img_pixel_put(t_img *img, int clr, int x, int y)
{
	if (clr & (0xFF << 030))
		return ;
	img_pixel_put_t(img, clr, x, y);
}
