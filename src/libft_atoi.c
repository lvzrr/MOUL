#include "libft.h"

int	libft_check_valid(char *str)
{
	int		l;
	char	*cp;

	l = 0;
	while (*str)
	{
		cp = str + 1;
		while (*cp)
		{
			if (*cp == '-'
				|| *cp == '+')
				return (-1);
			cp++;
		}
		str++;
		l++;
	}
	return (l);
}

int	libft_atoi(char *str)
{
	int		out;
	int		neg;
	int		len;

	len = libft_check_valid(str);
	out = 0;
	neg = 1;
	if (len == -1 || *str == 0)
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
		out = out * 10 + (*str++ - '0');
	return (out * neg);
}
