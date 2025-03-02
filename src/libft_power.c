#include "libft.h"

int	libft_power(int base, int exponent)
{
	if (exponent == 1)
		return (base);
	if (exponent == 0)
		return (1);
	return (base * libft_power(base, exponent - 1));
}
