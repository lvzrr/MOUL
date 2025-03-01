#include "test.h"

int	main()
{
	int c = 0;
	while (c < TESTNUM)
	{
		char *s1 = (char *)malloc(101 * sizeof(char));
		char *s2 = (char *)malloc(101 * sizeof(char));
		int l = 1 + rand() % 100;
		int w = 0;
		if (rand() % 2 == 0)
		{
			while (w < l)
			{
				s1[w] = 1 + rand() % 241;
				s2[w] = 1 + rand() % 241;
				w++;
			}
		}
		else
		{
			while (w < l)
			{
				s1[w] = 1 + rand() % 241;
				s2[w] = s1[w];
				w++;
			}
		}
		s1[w] = 0;
		s2[w] = 0;
		int r = rand() % l;
		int ft_res = ft_strncmp(s1, s2, r);
		int l_res = libft_strncmp(s1, s2, r);
		if (ft_res != l_res)
		{
			libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tstr1:  %s\n\t\t\tstr2: %s\n\n",l_res, ft_res, s1, s2);
			free(s1);
			free(s2);
			return (1);
		}
		free(s1);
		free(s2);
		c++;
	}
	return (0);
}
