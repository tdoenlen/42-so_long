#include "master.h"

int	get_img_pixel(t_img *img, int x, int y, int ratio)
{
	if (ratio > 0)
	{
		x /= ratio;
		y /= ratio;
	}
	else if (ratio < 0)
	{
		x *= -ratio;
		y *= -ratio;
	}
	if (x >= img->w || y >= img->h)
		printf("WARNING: getting pixel out of image: x%+d, y%+d\n",
			x - img->w + 1, y - img->h + 1);
	if (x >= img->w)
		x = img->w - 1;
	if (y >= img->h)
		y = img->h - 1;
	return (*((int *)(img->addr + y * img->l + x * img->p)));
}
