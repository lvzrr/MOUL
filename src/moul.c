#include "libft.h"

int	main(int argc, char **argv)
{
	int	level;

	if (argc < 2)
		return (1);
	level = libft_atoi(argv[1]);
	switch (level)
	{
		case 0:
			break;
		case 1:
			return libft_test(_01tests, 9);
		case 2:
			return libft_test(_02tests, 13);
		case 3:
			return libft_test(_03tests, 6);
	}
	return (0);
}
