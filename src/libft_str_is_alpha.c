#include "libft.h"

int	libft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!((*str >= 'a' && *str <= 'z')
				|| (*str >= 'A' && *str <= 'a')))
			return (1);
		str++;
	}
	return (0);
}
