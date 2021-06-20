#ifndef LIB_H
# define LIB_H

# define BUFFER_SIZE 32

typedef struct s_gnl_data
{
	char	buf[BUFFER_SIZE + 1];
	int		i;
	int		n;
	int		fd;
}	t_gnl_data;

int		get_next_line(int fd, char **line);

int		ft_strlen(char *s);
char	*ft_itoa(int n);

char	**add_str_to_tab(char *str, char **tab);

void	*safe_free(void *ptr);
char	**safe_free_str_tab(char **tab);
void	safe_destroy_img(void *mlx_ptr, t_img *img);
void	safe_free_anim(void *mlx_ptr, t_anim *anim);
void	safe_free_data(t_data *data);

#endif
