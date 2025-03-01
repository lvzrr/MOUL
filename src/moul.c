#include "libft.h"

int	main(int argc, char **argv)
{
	int	level;

if (argc < 2)
	{
		libft_printf("\nUsage: moul [options]\n");
		libft_printf("Options:\n");
		libft_printf("  0 - No tests\n");
		libft_printf("  1 - Run _01tests (9 cases)\n");
		libft_printf("  2 - Run _02tests (13 cases)\n");
		libft_printf("  3 - Run _03tests (6 cases)\n");
		libft_printf("  x - And so on...\n");
		libft_printf("  trace - Print trace of the last test\n");
		libft_printf("  help - Show this message\n\n");
		return (0);
	}

	if (libft_strcmp(argv[1], "help") == 0)
	{
		libft_printf("\nUsage: moul [options]\n");
		libft_printf("Options:\n");
		libft_printf("  0 - No tests\n");
		libft_printf("  1 - Run _01tests (9 cases)\n");
		libft_printf("  2 - Run _02tests (13 cases)\n");
		libft_printf("  3 - Run _03tests (6 cases)\n");
		libft_printf("  trace - Print trace of the last test\n");
		libft_printf("  help - Show this message\n\n");
		return (0);
	}

	if (libft_strcmp(argv[1], "trace") == 0)
	{
		// Implement logic to print trace of the last test
		libft_printf("Printing trace of the last test...\n");
		// Add actual trace logic here
		return (0);
	}

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
		default:
			libft_putstr("Invalid level. Run with 'help' for usage.\n");
			return (1);
	}
	return (0);
}
