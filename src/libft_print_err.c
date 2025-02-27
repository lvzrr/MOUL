#include "libft.h"

void	libft_print_err(char *str)
{
	while (*str)
		write(2, str++, 1);
}
