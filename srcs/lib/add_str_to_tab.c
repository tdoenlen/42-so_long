#include "master.h"

char	**add_str_to_tab(char *str, char **tab)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab && tab[i])
		i++;
	new_tab = malloc(sizeof(*new_tab) * (i + 2));
	if (new_tab == NULL)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	safe_free(tab);
	new_tab[i] = str;
	new_tab[i + 1] = NULL;
	return (new_tab);
}
