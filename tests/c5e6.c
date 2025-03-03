#include "test.h"

#undef TESTNUM
#define TESTNUM 100

int main()
{
	srand(time(NULL));
	int c = 0;
	while (c < TESTNUM)
	{
		int n = rand() % 100000;
		int ft = ft_is_prime(n);
		int libft = libft_is_prime(n);
		if (c % 10 == 0)
			w_trace("%d prime? -> %d (expected: %d)\n", n, ft, libft);
		if (ft != libft)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tnumber: %d\n\n", libft, ft, n);
			return (1);
		}
		c++;
	}
	return (0);
}
