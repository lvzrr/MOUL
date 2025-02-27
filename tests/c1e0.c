#include "test.h"

int	main(void)
{
	int	c;
	int	p;
	int i;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		p = rand();
		i = p;
		ft_ft(&p);
		if (p != 42)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\tinput:\t%d\n\t\t\toutput:\t%d\n\n",i, 42);
			return (1);
		}
		c++;
	}
	return (TESTPASSED);
}
