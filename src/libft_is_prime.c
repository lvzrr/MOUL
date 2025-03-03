#include "libft.h"

int	libft_is_prime(int nb)
{
	int	c;
	int	sq;

	c = 2;
	sq = libft_sqrt(nb);
	if (sq == 0)
		sq = nb - 1;
	while (c <= sq)
	{
		if (nb % c == 0)
			return (0);
		c++;
	}
	return (1);
}
