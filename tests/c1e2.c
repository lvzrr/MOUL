#include "test.h"

int	main(void)
{
	int	c;
	int	p1;
	int	p2;
	int	t1;
	int	t2;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		p1 = rand();
		p2 = rand();
		t1 = p1;
		t2 = p2;
		ft_swap(&p1, &p2);
		if (p1 != t2 || p2 != t1)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\tinput:\t%d, %d\n\t\t\toutput:\t%d, %d\n\n",t1, t2, p1, p2);
			return (0);
		}
		c++;
	}
	return (TESTPASSED);
}

