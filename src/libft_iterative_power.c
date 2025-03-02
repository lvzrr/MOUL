#include "libft.h"

int	libft_iterative_power(int nb, int power)
{
	if ((nb == 0 && power != 0)
		|| power <= 0)
		return (0);
	if (nb == 1 || (nb == 0
			&& power == 0))
		return (1);
	while (--power)
		nb *= nb;
	return (nb);
}
