#include "libft.h"

void	libft_putnbr(int n)
{
	char	out;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		libft_putnbr(n / 10);
	}
	out = '0' + (n % 10);
	write(1, &out, 1);
}
