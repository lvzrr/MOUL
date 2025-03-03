#include "libft.h"

int	libft_factorial(int n)
{
	if (n == 0)
		return (1);
	return (n * libft_factorial(n - 1));
}
