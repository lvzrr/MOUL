#include "libft.h"

unsigned int	libft_strlcpy(char *dest, char *src, unsigned int size)
{
	while (*dest)
		dest++;
	while(*src && --size)
		*dest++ = *src++;
	*dest = 0;
	return libft_strlen(src);
}
