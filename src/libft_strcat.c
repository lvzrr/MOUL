#include "libft.h"

char	*libft_strcat(char *dest, char *src)
{
	char	*origin;

	origin = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (origin);
}
