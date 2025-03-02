#include "test.h"

int main()
{
	srand(time(NULL));
	int c = 0;
	while (c < TESTNUM)
	{
		int base = rand() % 12;
		int ft = ft_recursive_factorial(base);
		int lib = libft_factorial(base);
		if (ft != lib)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tnum: %d\n", lib, ft, base);
			return (1);
		}
		c++;
	}
	return (0);
}
