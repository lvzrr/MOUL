#include "libft.h"

int	libft_sqrt(int nb)
{
	int	init;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	init = 1;
	while (init < 46341 && init * init <= nb + 1)
	{
		if (init * init == nb)
			return (init);
		init++;
	}
	return (0);
}
