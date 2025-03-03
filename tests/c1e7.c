#include "test.h"

#undef TESTNUM
#define TESTNUM 1000000

int	main(void)
{
	int		c;
	int		c2;
	int		*tab;
	int		*tab2;
	int		l;
	int		tmp;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		c2 = 0;
		l = rand() % 100;
		tab = (int*) malloc(sizeof(int) * l);
		tab2 = (int*) malloc(sizeof(int) * l);
		if (c % 100000 == 0)
    		 w_trace("reversing tab of length %d\n", l);
		while(c2 < l)
		{
			tmp = rand();
			tab[c2] = tmp;
			tab2[c2++] = tmp;
		}
		c2 = 0;
		ft_rev_int_tab(tab, l);
		while(c2 < l)
		{
			if(tab[c2] != tab2[l - c2 - 1])
			{
				libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m (no debug)\n\n");
				free(tab);
				free(tab2);
				return (0);
			}
			c2++;
		}
		c++;
		free(tab);
		free(tab2);
	}
	return (TESTPASSED);
}
