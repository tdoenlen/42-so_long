#include "master.h"

static void	inc_path(char *path, int num_i)
{
	(path[num_i])++;
	if (path[num_i] == 58)
	{
		path[num_i] = '0';
		(path[num_i - 1])++;
	}
}

static char	*ft_str_copy(char *s)
{
	char	*copy;
	int		i;

	copy = malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

static t_img	get_frame(char *path_one, int rem_f, t_data *data)
{
	static char	*last_path = NULL;
	static int	num_i;
	t_img		frame;

	if (last_path == NULL)
	{
		last_path = ft_str_copy(path_one);
		if (last_path == NULL)
			error("Allocation failed", data);
		data->str_to_free = last_path;
		num_i = ft_strlen(path_one);
		while (path_one[num_i] != '0')
			num_i--;
	}
	else
		inc_path(last_path, num_i);
	frame = new_img_from_png(last_path, data);
	if (!rem_f)
	{
		free(last_path);
		last_path = NULL;
		data->str_to_free = NULL;
	}
	return (frame);
}

static void	set_frames_ptr_to_null(t_anim *anim)
{
	int	i;

	i = 0;
	while (i < anim->nb_f)
	{
		anim->f_tab[i].ptr = NULL;
		i++;
	}
}

t_anim	new_anim_from_ttrs(char *path_one, int nb_frames, double time,
	t_data *data)
{
	t_anim	anim;
	int		i;

	anim.f_tab = malloc(sizeof(*(anim.f_tab)) * nb_frames);
	if (anim.f_tab == NULL)
		error("Failed to allocate anim frames", data);
	anim.nb_f = nb_frames;
	data->anim_to_free = &anim;
	set_frames_ptr_to_null(&anim);
	i = 0;
	while (i < nb_frames)
	{
		anim.f_tab[i] = get_frame(path_one, nb_frames - 1 - i, data);
		i++;
	}
	data->anim_to_free = NULL;
	anim.cur_f = anim.f_tab;
	anim.cur_t = 0.;
	anim.max_t = time;
	return (anim);
}
