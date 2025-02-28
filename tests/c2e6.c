#include "test.h"

#undef TESTNUM
#define TESTNUM 100000

int	main(void)
{
	int c = 0;
	while (c < TESTNUM)
	{
		int l = rand() % 100;
		int c2 = 0;
		char *str = (char *)malloc(101 * sizeof(char));
		while (c2 < l)
			str[c2++] = 1 + rand() % 254;
		int lib_res = libft_str_is_printable(str);
		int ft_res = ft_str_is_printable(str);
		if(ft_res != lib_res)
		{
            libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tstr: %s\n\n", lib_res, ft_res, str);
			free(str);
			return (1);
		}
		free(str);
		c++;
	}
	return (TESTPASSED);
}
