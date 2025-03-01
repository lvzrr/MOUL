#include "test.h"

int	main()
{
	srand(time(NULL));
	int	c = 0;
	while (c < TESTNUM)
	{
		char *src = (char *)malloc(101 * sizeof(char));
		char *dst= (char *)malloc(101 * sizeof(char));
		char *dst2= (char *)malloc(101 * sizeof(char));
		int l = rand() % 49;
		int c2 = 0;
		while (c2 < l)
			src[c2++] = 1 + rand() % 244;
		src[c2] = 0;
		l = rand() % 49;
		c2 = 0;
		while (c2 < l)
		{
			dst[c2] = 1 + rand() % 244;
			dst2[c2] = dst[c2];
			c2++;
		}
		dst[c2] = 0;
		dst2[c2] = 0;
		int n = rand() % 49;
		char *got = ft_strncat(dst, src, n);
		char *ex = libft_strncat(dst2, src, n);
		if (libft_strcmp(ex,got)!=0)
		{
			libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %s\n\t\t\tsrc:  %s\n\t\t\tsize: %d\n\n",ex, got, src, n);
			free(src);
			free(dst);
			free(dst2);
			return (1);
		}

		free(src);
		free(dst);
		free(dst2);
		c++;
	}
	return (0);
}
