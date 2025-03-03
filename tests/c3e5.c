#include "test.h"

int	main()
{
	srand(time(NULL));
	int	c = 0;
	while (c < TESTNUM)
	{
		char *src = (char *)calloc(101, sizeof(char));
		char *dst = (char *)calloc(101, sizeof(char));
		char *dst2 = (char *)calloc(101, sizeof(char));
		int l = rand() % 40;
		int c2 = 0;
		while (c2 < l)
			src[c2++] = ' ' + rand() % 95;
		src[c2] = 0;
		l = rand() % 49;
		c2 = 0;
		while (c2 < l)
		{
			dst[c2] = ' ' + rand() % 95;
			dst2[c2] = dst[c2];
			c2++;
		}
		dst[c2] = 0;
		dst2[c2] = 0;
		int n = rand() % 30;
		unsigned int got = ft_strlcat(dst, src, n);
		unsigned int ex = libft_strlcat(dst2, src, n);
		if (c % 100000 == 0)
			w_trace("src: %s\ndst: %s\nreturn: %d\n",src, dst, got);
		if (ex != got || libft_strcmp(dst, dst2) != 0)
		{
			libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tsrc:  %s\n\t\t\tdst: %s\n\n",ex, got, src, dst2);
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
