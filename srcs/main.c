#include "master.h"

static void	init_anims(t_data *data)
{
	data->anims.f.d.f_tab = NULL;
	data->anims.f.l.f_tab = NULL;
	data->anims.f.r.f_tab = NULL;
	data->anims.f.u.f_tab = NULL;
	data->anims.p.d.f_tab = NULL;
	data->anims.p.l.f_tab = NULL;
	data->anims.p.r.f_tab = NULL;
	data->anims.p.u.f_tab = NULL;
	data->anims.e.f_tab = NULL;
}

static void	init_ttrs(t_data *data)
{
	data->ttrs.bg.b_b.ptr = NULL;
	data->ttrs.bg.b_tree.ptr = NULL;
	data->ttrs.bg.bl_b.ptr = NULL;
	data->ttrs.bg.br_b.ptr = NULL;
	data->ttrs.bg.bush.ptr = NULL;
	data->ttrs.bg.grass.ptr = NULL;
	data->ttrs.bg.l_b.ptr = NULL;
	data->ttrs.bg.o_trees.ptr = NULL;
	data->ttrs.bg.r_b.ptr = NULL;
	data->ttrs.bg.t_b.ptr = NULL;
	data->ttrs.bg.t_tree.ptr = NULL;
	data->ttrs.bg.tl_b.ptr = NULL;
	data->ttrs.bg.tr_b.ptr = NULL;
	data->ttrs.col0.ptr = NULL;
	data->ttrs.col1.ptr = NULL;
	data->ttrs.exit0.ptr = NULL;
	data->ttrs.exit1.ptr = NULL;
}

static void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		error("Failed to initialize mlx", NULL);
	init_anims(data);
	init_ttrs(data);
	data->anim_to_free = NULL;
	data->bg_img.ptr = NULL;
	data->win_img.ptr = NULL;
	data->map = NULL;
	data->nb_mov_str = ft_itoa(0);
	if (data->nb_mov_str == NULL)
		error("nb_mov_str allocation failed", data);
	data->str_to_free = NULL;
	data->map_w = 0;
	data->map_h = 0;
	data->delta = 0.;
	data->plr.anim = &(data->anims.p.d);
	data->plr.x = 0;
	data->plr.y = 0;
	data->foes = NULL;
	data->nb_c = 0;
	data->e_x = 0;
	data->e_y = 0;
	data->nb_mov = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	if (argc != 2)
		error("You must give one argument", NULL);
	data.fd = open_file(argv[1]);
	parse_file(&data);
	close(data.fd);
	init_game(&data);
	printf("Done!\n\n");
	mlx_loop(data.mlx);
}
