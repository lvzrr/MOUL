#include "libft.h"

const char *banner = 
"\n\n\t███╗   ███╗ █████╗ ██╗   ██╗██╗\n"
"\t████╗ ████║██╔══██╗██║   ██║██║\n"
"\t██╔████╔██║██║  ██║██║   ██║██║\n"
"\t██║╚██╔╝██║██║  ██║██║   ██║██║\n"
"\t██║ ╚═╝ ██║╚█████╔╝╚██████╔╝███████╗\n"
"\t╚═╝     ╚═╝ ╚════╝  ╚═════╝ ╚══════╝\n";

int	main(int argc, char **argv)
{
	
	int	level;

	if (argc < 2)
	{
		libft_printf("Usage: moul [options]\n");
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
		libft_printf("  x - And so on...\n");
		libft_printf("  trace - Print trace of the last test\n");
		libft_printf("  help - Show this message\n\n");
		return (0);
	}

	if (libft_strcmp(argv[1], "trace") == 0)
	{
		char *p = getenv("MOUL_TRACE");
		if (!p)
		{
			fprintf(stderr, "MOUL_TRACE not set\n");
			return 1;
		}
		FILE *fp = fopen(p, "r");
		if (!fp)
		{
			perror("Error opening file");
			return 1;
		}
		if (fseek(fp, 0, SEEK_END) != 0)
		{
			perror("fseek error");
			fclose(fp);
			return 1;
		}
		long size = ftell(fp);
		if (size < 0)
		{
			perror("ftell error");
			fclose(fp);
			return 1;
		}
		rewind(fp);
		char *filecontents = (char *)malloc((size + 1) * sizeof(char));
		if (!filecontents)
		{
			perror("Memory allocation failed");
			fclose(fp);
			return 1;
		}
		size_t bytesRead = fread(filecontents, 1, size, fp);
		if (bytesRead != (size_t)size)
		{
			perror("Error reading file");
			free(filecontents);
			fclose(fp);
			return 1;
		}
		filecontents[bytesRead] = '\0';
		fclose(fp);
		printf("%s", filecontents);
		free(filecontents);
		return (0);
	}

	libft_printf("%s\t\t\t\tA Moulinette Wannabe\n\n", banner);
	init_trace();
	level = libft_atoi(argv[1]);
	w_trace(banner);
	w_trace("\t\t\t\t\tA Moulinette Wannabe\n\n");
	w_trace("========STARTING JOB FOR C%02d========\n",level);
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
		case 4:
			return libft_test(_04tests, 6);
		case 5:
			libft_printf("\n\n\t\t\e[1;91mWARNING\e[0m: SLOW TESTS\n\n");
			return libft_test(_05tests, 9);
		default:
			libft_putstr("Invalid level. Run with 'help' for usage.\n");
			return (1);
	}
	return (0);
}
