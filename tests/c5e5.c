#include "test.h"

int main()
{
	srand(time(NULL));
	int c = 0;
	while (c < TESTNUM)
	{
		int n = rand() % 46342;
		int ft;
		if (c % 10 == 0)
		{
			ft = ft_sqrt(-(n * n));
			if (c % 100000 == 0)
				w_trace("sqrt(%d) -> %d (expected: %d)\n", -n * n, ft, 0);
			n = 0;
		}
		else 
		{
			ft = ft_sqrt(n * n);
			if (c % 1000000 == 0)
				w_trace("sqrt(%d) -> %d (expected: %d)\n", n * n, ft, n);
		}
		if (n == 46341)
			n = 0;
		if (ft != n)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\n", n, ft);
			return (1);
		}
		c++;
	}
	return (0);
}
