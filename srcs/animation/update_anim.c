#include "master.h"

int	update_anim(t_anim *anim, t_data *data)
{
	int	ret;

	ret = 0;
	anim->cur_t += data->delta;
	while (anim->cur_t >= anim->max_t)
	{
		anim->cur_t -= anim->max_t;
		ret = 1;
	}
	anim->cur_f = anim->f_tab
		+ (int)floor(anim->cur_t / anim->max_t * (double)anim->nb_f);
	return (ret);
}
