#include "master.h"

static void	ft_itoa_fill_ret(char *ret, int i, int n)
{
	if (n >= 10)
		ft_itoa_fill_ret(ret, i - 1, n / 10);
	if (i >= 0)
		ret[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		calc;
	int		size;

	size = 0;
	if (!n)
		size++;
	calc = n;
	while (calc)
	{
		calc /= 10;
		size++;
	}
	ret = malloc(sizeof(*ret) * (size + 1));
	if (ret == NULL)
		return (NULL);
	ret[size] = 0;
	ft_itoa_fill_ret(ret, size - 1, n);
	return (ret);
}
