#ifndef TEXTURE_STRUCT_H
# define TEXTURE_STRUCT_H

typedef struct s_image
{
	void	*ptr;
	char	*addr;
	int		w;
	int		h;
	int		l;
	int		p;
	int		e;
}	t_img;

typedef struct s_animation
{
	t_img	*cur_f;
	t_img	*f_tab;
	double	cur_t;
	double	max_t;
	int		nb_f;
}	t_anim;

#endif