#include "master.h"

static void	load_anims(t_data *data)
{
	data->anims.f.d = new_anim_from_ttrs("textures/foe_d0.png", 4, ANIMTIME_F,
			data);
	data->anims.f.l = new_anim_from_ttrs("textures/foe_l0.png", 4, ANIMTIME_F,
			data);
	data->anims.f.r = new_anim_from_ttrs("textures/foe_r0.png", 4, ANIMTIME_F,
			data);
	data->anims.f.u = new_anim_from_ttrs("textures/foe_u0.png", 4, ANIMTIME_F,
			data);
	data->anims.p.d = new_anim_from_ttrs("textures/player_d0.png", 2,
			ANIMTIME_F, data);
	data->anims.p.l = new_anim_from_ttrs("textures/player_l0.png", 2,
			ANIMTIME_F, data);
	data->anims.p.r = new_anim_from_ttrs("textures/player_r0.png", 2,
			ANIMTIME_F, data);
	data->anims.p.u = new_anim_from_ttrs("textures/player_u0.png", 2,
			ANIMTIME_F, data);
	data->anims.e = new_anim_from_ttrs("textures/exit_open00.png", 14,
			ANIMTIME_E, data);
}

void	load_ttrs(t_data *data)
{
	data->ttrs.bg.b_b = new_img_from_png("textures/bottom_border.png", data);
	data->ttrs.bg.b_tree = new_img_from_png("textures/tree_bottom.png", data);
	data->ttrs.bg.bl_b = new_img_from_png(\
"textures/bottom_left_border.png", data);
	data->ttrs.bg.br_b = new_img_from_png(\
"textures/bottom_right_border.png", data);
	data->ttrs.bg.bush = new_img_from_png("textures/bush.png", data);
	data->ttrs.bg.grass = new_img_from_png("textures/grass.png", data);
	data->ttrs.bg.l_b = new_img_from_png("textures/left_border.png", data);
	data->ttrs.bg.o_trees = new_img_from_png(\
"textures/overlapping_trees.png", data);
	data->ttrs.bg.r_b = new_img_from_png("textures/right_border.png", data);
	data->ttrs.bg.t_b = new_img_from_png("textures/top_border.png", data);
	data->ttrs.bg.t_tree = new_img_from_png("textures/tree_top.png", data);
	data->ttrs.bg.tl_b = new_img_from_png("textures/top_left_border.png", data);
	data->ttrs.bg.tr_b = new_img_from_png(\
"textures/top_right_border.png", data);
	data->ttrs.col0 = new_img_from_png("textures/collectible.png", data);
	data->ttrs.col1 = new_img_from_png("textures/collectible_taken.png", data);
	data->ttrs.exit0 = new_img_from_png("textures/exit.png", data);
	data->ttrs.exit1 = new_img_from_png("textures/exit_open.png", data);
	load_anims(data);
}
