#include "test.h"
int main()
{
	
	int c = 0;
	while (c < TESTNUM)
	{
		int base = rand() % 10;
		int exp = rand() % 5;
		int ft = ft_iterative_power(base, exp);
		int lib = libft_iterative_power(base, exp);
		if (ft != lib)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tbase: %d\n\t\t\texp: %d\n\n", lib, ft, base, exp);
			return (1);
		}
		c++;
	}
	return (0);
}
