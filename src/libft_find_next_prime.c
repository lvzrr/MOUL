#include "libft.h"

int	libft_find_next_prime(int nb)
{
	while (!libft_is_prime(nb))
		nb++;
	return (nb);
}
