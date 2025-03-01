#include "test.h"

int	main()
{
	srand(time(NULL));
	int	c = 0;
	while (c < TESTNUM)
	{
		char *haystack = (char *)malloc(101 * sizeof(char));
		int	c2 = 0;
		int	l =  1 + rand() % 99;
		while (c2 < l)
 			haystack[c2++] = ' ' + (rand() % 95);
		haystack[c2] = 0;
		int needle_pos = rand() % (l / 2);
		char *needle = strdup(haystack + needle_pos);
		char *ft_res = ft_strstr(haystack, needle);
		if (ft_res == NULL)
		{
			libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %s\n\t\t\tgot: %s\n\t\t\thaystack:  %s\n\n",needle, "(null)", haystack);
			free(haystack);
			return (1);
		}
		if (libft_strcmp(ft_res,needle)!=0)
		{
			libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %s\n\t\t\tgot: %s\n\t\t\thaystack:  %s\n\n",needle, ft_res, haystack);
			free(haystack);
			free(needle);
			return (1);
		}

		free(haystack);
		free(needle);
		c++;
	}
	return (0);
}
