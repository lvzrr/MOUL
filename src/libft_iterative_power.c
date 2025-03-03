#include "libft.h"

int	ft_iterative_power(int nb, int power)
{
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	while (i++ < power)
		nb *= nb;
	return (nb);
}
