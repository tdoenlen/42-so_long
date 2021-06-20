#include "master.h"

int	get_dir(int foe_pos, int plr_pos)
{
	int	ret;

	ret = foe_pos - plr_pos;
	if (ret < 0)
		return (1);
	if (ret > 0)
		return (-1);
	return (0);
}
