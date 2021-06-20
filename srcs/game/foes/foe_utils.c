#include "master.h"

t_foe	*foe_add(int x, int y, t_data *data)
{
	t_foe	**last;

	last = &(data->foes);
	while (*last)
		last = (t_foe **)&((*last)->next);
	*last = malloc(sizeof(**last));
	if (*last == NULL)
		error("New foe allocation failed", data);
	(*last)->x = x;
	(*last)->y = y;
	(*last)->anim = &(data->anims.f.d);
	(*last)->next = NULL;
	return (*last);
}

void	foe_rm(t_foe *rm_foe, t_data *data)
{
	t_foe	*ptr;
	t_foe	*prev;

	prev = data->foes;
	ptr = data->foes;
	while (ptr && ptr != rm_foe)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == NULL)
		return ;
	prev->next = ptr->next;
	if (ptr == prev)
		data->foes = ptr->next;
	free(ptr);
}

void	foe_clr(t_data *data)
{
	t_foe	*next;

	while (data->foes)
	{
		next = data->foes->next;
		free(data->foes);
		data->foes = next;
	}
}

void	check_is_plr_colliding_foe(t_data *data)
{
	t_foe	*foe;

	foe = data->foes;
	while (foe)
	{
		if (foe->x == data->plr.x && foe->y == data->plr.y)
		{
			data->plr.y = 0;
			foe = NULL;
		}
		else
			foe = foe->next;
	}
}
