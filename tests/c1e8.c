#include "test.h"

#undef TESTNUM
#define TESTNUM 10000

int	main(void)
{
	int		c;
	int		c2;
	int		*tab;
	int		l;
	int		tmp;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		c2 = 0;
		l = rand() % 1000;
		tab = (int*) malloc(sizeof(int) * l);
		while(c2 < l)
		{
			tmp = rand();
			tab[c2++] = tmp;
		}
		c2 = 1;
		ft_sort_int_tab(tab, l);
		tmp = tab[0];
		while(c2 < l)
		{
			if(tmp > tab[c2])
			{
				libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m (no debug)\n\n");
				free(tab);
				return (0);
			}
			tmp = tab[c2];
			c2++;
		}
		c++;
		free(tab);
	}
	return (TESTPASSED);
}
