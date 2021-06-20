#include "master.h"

static void	check_has_ber_ext(char *file)
{
	int		i_file;
	int		i_ext;
	char	*ext;

	i_file = 0;
	i_ext = 4;
	ext = ".ber";
	while (file[i_file])
		i_file++;
	while (i_ext > 0)
	{
		i_ext--;
		i_file--;
		if (i_file == -1 || file[i_file] != ext[i_ext])
			error("The map file does not have the '.ber' extension", NULL);
	}
}

int	open_file(char *path)
{
	int	fd;

	check_has_ber_ext(path);
	printf("Open file...\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		error("Unable to open the map file", NULL);
	return (fd);
}
