# "headtests.h"

int main(void) 
{
	srand(time(NULL));
	int	c;

	c = 0;
	while (c < TESTNUM)
	{
		int value = rand();
		int *p1 = &value;
		int **p2 = &p1;
		int ***p3 = &p2;
		int ****p4 = &p3;
		int *****p5 = &p4;
		int ******p6 = &p5;
		int *******p7 = &p6;
		int ********p8 = &p7;
		int *********p9 = &p8;
		ft_ultimate_ft(p9);
		if (*********p9 != 42)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m:\n\t\t\tinput:\t%d\n\t\t\toutput:\t%d\n\n",*********p9, 42);
			return (1);
		}
		c++;
	}
    return (0);
}
