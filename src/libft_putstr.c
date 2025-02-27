#include "libft.h"

void	libft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}
