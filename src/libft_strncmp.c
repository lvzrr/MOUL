#include "libft.h"

int	libft_strncmp(char *s1, char *s2, int size)
{
	while (size > 0)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		size--;
	}
	return (0);
}
