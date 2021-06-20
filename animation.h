#ifndef ANIMATION_H
# define ANIMATION_H

# include "data.h"

# define ANIMTIME_F 0.6
# define ANIMTIME_P 0.3
# define ANIMTIME_E 1.0

t_anim	new_anim_from_ttrs(char *path_one, int nb_frames, double time,
			t_data *data);
int		update_anim(t_anim *anim, t_data *data);

#endif
