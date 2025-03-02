#include "libft.h"

int	libft_fibonacci(int n)
{
	if (n == 1)
		return (1);
	if (n == 2)
		return (1);
	return (libft_fibonacci(n - 1) + libft_fibonacci(n - 2));
}
