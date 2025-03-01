#include "test.h"

int	main()
{
	int c =  0;
	while (c < TESTNUM)
	{
		char *s = (char *)malloc(101 * sizeof(char));
		char *o = (char *)malloc(101 * sizeof(char));
		int l = rand() % 100;
		int m = 0;
		while (m < l)
		{
			s[m] = ' ' + rand() % 95;
			o[m] = s[m];
			m++;
		}
		s[m] = 0;
		o[m] = 0;
		char *resft = ft_strcapitalize(s);
		char *reslibft = libft_strcapitalize(o);
		if (libft_strcmp(resft, reslibft) != 0)
		{
			libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\tsrc: %s\n\t\t\tgot: %s\n\n", reslibft, resft);
			free(resft);
			free(reslibft);
			return (1);

		}
		c++;
		free(resft);
		free(reslibft);
	}
	return (0);
}


