#include "libft.h"

int	libft_fibonacci(int n)
{
	if (n <= 0)
		return (0);
	if (n <= 2)
		return (1);
	return (libft_fibonacci(n - 1) + libft_fibonacci(n - 2));
}
