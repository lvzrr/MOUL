#include "libft.h"

unsigned int	libft_strlen(char *str)
{
	unsigned int	l;

	l = 0;
	while (*str)
		l++;
	return (l);
}
