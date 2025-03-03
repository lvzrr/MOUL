#include "test.h"

int	main(void)
{
	int	c;
	int	p1;
	int	p2;
	int	ptr1;
	int	ptr2;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		p1 = rand();
		ptr1 = p1;
		p2 = rand();
		ptr2 = p2;
		ft_ultimate_div_mod(&ptr1, &ptr2);
        if (c % 10000 == 0)
			w_trace("x : %d\ty : %d -> x : %d\ty : %d\n", p1, p2, ptr1, ptr2);
		if (ptr1 != p1 / p2 || ptr2 != p1 % p2)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\tinput:\t%d, %d\n\t\t\toutput:\t%d, %d\n\n",p1,p2,ptr1,ptr2);
			return (1);
		}
		c++;
	}
	return (TESTPASSED);
}
