#include "libft.h"

char *libft_gen_rand_str(unsigned int max_size)
{
	int		i;
	char	*out;

	if (max_size > 99)
		max_size = 100;
	out = (char *)malloc(101 * sizeof(char));
	i = 0;
	while ((unsigned int)i < max_size)
		out[i++] = (char)(20 + rand() % 200);
	out[i] = 0;
	return (out);
}
