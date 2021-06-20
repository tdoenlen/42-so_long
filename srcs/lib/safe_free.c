#include "master.h"

void	*safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

char	**safe_free_str_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	safe_destroy_img(void *mlx_ptr, t_img *img)
{
	if (img->ptr)
		mlx_destroy_image(mlx_ptr, img->ptr);
	img->ptr = NULL;
}

void	safe_free_anim(void *mlx_ptr, t_anim *anim)
{
	int	i;

	if (anim == NULL || anim->f_tab == NULL)
		return ;
	i = 0;
	while (i < anim->nb_f)
	{
		safe_destroy_img(mlx_ptr, anim->f_tab + i);
		i++;
	}
	anim->f_tab = NULL;
}
