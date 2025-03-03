#include "test.h"

int main()
{
	
	int c = 0;
	while (c < TESTNUM)
	{
		int base = rand() % 12;
		int ft = ft_iterative_factorial(base);
		int lib = libft_factorial(base);
		if (c % 100000 == 0)
			w_trace("%d! = %d (expected %d)\n", base, ft, lib);
		if (ft != lib)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tnumber: %d\n\n", lib, ft, base);
			return (1);
		}
		c++;
	}
	return (0);
}
