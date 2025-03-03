#include "libft.h"

void	w_trace(const char *fmt, ...)
{
	char *c = getenv("MOUL_TRACE");
	if (!c) {
		write(2, "MOUL_TRACE not set\n", 19);
		exit(1);
	}
	FILE *fp = fopen(c, "a");
	if (fp != NULL)
	{
		va_list args;
		va_start(args, fmt);
		vfprintf(fp, fmt, args);
		va_end(args);

		fclose(fp);
	}
	else
	{
		write(2, "Error opening file\n", 19);
		exit(1);
	}
}

void	init_trace(void) {
	char *c = getenv("MOUL_TRACE");
	FILE *fp = fopen(c, "w");
	if (fp != NULL) {
		fprintf(fp," ");
		fclose(fp);
	} else {
		write(2, "Error opening file\n", 18);
	}
}
