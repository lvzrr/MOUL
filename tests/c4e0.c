#include "test.h"

int	main(void)
{
	int c = 0;
	while (c < TESTNUM)
	{
		char *str = (char *)malloc(101 * sizeof(char));
		int c2 = 0;
		int l = rand() % 100;
		while (c2 < l)
		{
			str[c2++] = ' ' + rand() % 95;
		}
		str[c2] = 0;
		int r = ft_strlen(str);
		if(r != l)
		{
			libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tstr:  %s\n\n", l, r, str);
			free(str);
			return (1);
		}
		free(str);
		c++;
	}
	return (0);
}
