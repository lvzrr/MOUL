#include "libft.h"

int	libft_atoi(char *str)
{
	int	neg;
	int	out;

	neg = 1;
	out = 0;
	if (!*str)
		return (0);
	while (*str < 42)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out * neg);
}
