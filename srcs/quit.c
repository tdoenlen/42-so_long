#include "master.h"

int	quit(t_data *data)
{
	safe_free_data(data);
	exit(1);
}

void	error(char *msg, t_data *data)
{
	printf("\033[1m\033[31mError\033[37m\n");
	printf("%s", msg);
	printf("\033[0m\n");
	quit(data);
}
