#include "libft.h"

int	main(int argc, char **argv)
{
	int	level;

	if (argc < 2)
		return (1);
	level = libft_atoi(argv[1]);
	if (level == 1)
		return libft_test01();

	return (0);
}
