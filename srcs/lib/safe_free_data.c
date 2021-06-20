#include "master.h"

static void	safe_free_anims(t_data *data)
{
	safe_free_anim(data->mlx, &(data->anims.f.d));
	safe_free_anim(data->mlx, &(data->anims.f.l));
	safe_free_anim(data->mlx, &(data->anims.f.r));
	safe_free_anim(data->mlx, &(data->anims.f.u));
	safe_free_anim(data->mlx, &(data->anims.p.d));
	safe_free_anim(data->mlx, &(data->anims.p.l));
	safe_free_anim(data->mlx, &(data->anims.p.r));
	safe_free_anim(data->mlx, &(data->anims.p.u));
	safe_free_anim(data->mlx, &(data->anims.e));
}

static void	safe_free_ttrs(t_data *data)
{
	safe_destroy_img(data->mlx, &(data->ttrs.bg.b_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.b_tree));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.bl_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.br_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.bush));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.grass));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.l_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.o_trees));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.r_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.t_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.t_tree));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.tl_b));
	safe_destroy_img(data->mlx, &(data->ttrs.bg.tr_b));
	safe_destroy_img(data->mlx, &(data->ttrs.col0));
	safe_destroy_img(data->mlx, &(data->ttrs.col1));
	safe_destroy_img(data->mlx, &(data->ttrs.exit0));
	safe_destroy_img(data->mlx, &(data->ttrs.exit1));
}

void	safe_free_data(t_data *data)
{
	if (data == NULL)
		return ;
	safe_free_anims(data);
	safe_free_ttrs(data);
	safe_free_anim(data->mlx, data->anim_to_free);
	foe_clr(data);
	safe_destroy_img(data->mlx, &(data->bg_img));
	safe_destroy_img(data->mlx, &(data->win_img));
	safe_free_str_tab(data->map);
	safe_free(data->nb_mov_str);
	safe_free(data->str_to_free);
}
