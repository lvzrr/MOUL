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
			return libft_test01();
		case 2:
			return libft_test02();
		case 3:
			return libft_test03();
	}
	return (0);
}
