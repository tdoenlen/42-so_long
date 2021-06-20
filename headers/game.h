#ifndef GAME_H
# define GAME_H

# include "data.h"

void	put_ttr_to_dest_tile(t_img *ttr, int x_i, int y_i, t_data *data);
void	fill_win_img_with_clr(int clr, t_data *data);

void	fill_bg(t_data *data);
void	load_ttrs(t_data *data);
void	init_game(t_data *data);
void	reset_game(t_data *data);

void	update_bg_img(t_data *data);
void	update_win_img(t_data *data);

int		update(t_data *data);
int		key_just_pressed(int key, t_data *data);

t_foe	*foe_add(int x, int y, t_data *data);
void	foe_rm(t_foe *rm_foe, t_data *data);
void	foe_clr(t_data *data);
void	check_is_plr_colliding_foe(t_data *data);
int		get_dir(int foe_pos, int plr_pos);
void	move_foes(t_data *data);

#endif
