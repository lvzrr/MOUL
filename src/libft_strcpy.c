#include "libft.h"

char *libft_strcpy(char *dest, char *src)
{
	char	*aux;

	aux = dest;
	while (*dest && *src)
		*dest++ = *src++;
	*dest = 0;
	return (aux);
}
