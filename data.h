#ifndef DATA_H
# define DATA_H

# include "texture_struct.h"

typedef struct s_foe_info
{
	void	*next;
	int		x;
	int		y;
	t_anim	*anim;
}	t_foe;

typedef struct s_player_info
{
	int		x;
	int		y;
	t_anim	*anim;
}	t_plr;

typedef struct s_player_animations
{
	t_anim	d;
	t_anim	l;
	t_anim	r;
	t_anim	u;
}	t_p_anims;

typedef struct s_foe_animations
{
	t_anim	d;
	t_anim	l;
	t_anim	r;
	t_anim	u;
}	t_f_anims;

typedef struct s_animations
{
	t_p_anims	p;
	t_f_anims	f;
	t_anim		e;
}	t_anims;

typedef struct s_background_textures
{
	t_img	grass;
	t_img	tl_b;
	t_img	t_b;
	t_img	tr_b;
	t_img	l_b;
	t_img	r_b;
	t_img	bl_b;
	t_img	b_b;
	t_img	br_b;
	t_img	b_tree;
	t_img	t_tree;
	t_img	o_trees;
	t_img	bush;
}	t_bg;

typedef struct s_textures
{
	t_bg	bg;
	t_img	col0;
	t_img	col1;
	t_img	exit0;
	t_img	exit1;
}	t_ttrs;

typedef struct s_data
{
	t_anims	anims;
	t_ttrs	ttrs;
	t_plr	plr;
	t_foe	*foes;
	t_anim	*anim_to_free;
	t_img	bg_img;
	t_img	win_img;
	t_img	*dest_img;
	void	*mlx;
	void	*win;
	char	**map;
	char	*nb_mov_str;
	char	*str_to_free;
	double	delta;
	int		w;
	int		h;
	int		fd;
	int		map_w;
	int		map_h;
	int		nb_c;
	int		e_x;
	int		e_y;
	int		tile_dim;
	int		ratio;
	int		nb_mov;
}	t_data;

#endif
