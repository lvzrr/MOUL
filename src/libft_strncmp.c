#include "libft.h"

int	libft_strncmp(char *s1, char *s2, unsigned int size)
{
	if (size == 0)
		return (0);
	while (size-- > 0)
	{
		if (*s1 != *s2 || !*s1 || !*s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
