#include "test.h"

int main()
{
	
	int c = 0;
	while (c < TESTNUM)
	{
		int n = rand() % 46340;
		int ft = ft_sqrt(n * n);
		if (ft != n)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\n", n, ft);
			return (1);
		}
		c++;
	}
	return (0);
}
