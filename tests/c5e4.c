#include "test.h"

int main()
{
	
	int c = 0;
	while (c < TESTNUM)
	{
		int n = rand() % 20;
		int ft = ft_fibonacci(n);
		int lib = libft_fibonacci(n);
		if (ft != lib)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tnum: %d\n\n", lib, ft, n);
			return (1);
		}
		c++;
	}
	return (0);
}
