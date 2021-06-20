#ifndef MASTER_H
# define MASTER_H

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"

# include <time.h>
# include <sys/time.h>

# include "animation.h"
# include "data.h"
# include "events.h"
# include "game.h"
# include "image.h"
# include "lib.h"
# include "parsing.h"

# define TILE_DIM 32

int		quit(t_data *data);
void	error(char *msg, t_data *data);

#endif
