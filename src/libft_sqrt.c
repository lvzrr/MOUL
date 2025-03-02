#include "libft.h"

int	libft_sqrt(int nb)
{
	int	init;

	if (nb == 1)
		return (nb);
	if (nb < 0)
		return (0);
	init = 2;
	while (init < 46341)
	{
		if (init * init == nb)
			return (init);
		init++;
	}
	return (0);
}
