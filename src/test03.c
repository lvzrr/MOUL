#include "libft.h"

int _03ex00(void) { return compile_and_run("tests/c3e0.c", "ex00/ft_strcmp.c", "c3e0", 0); }
int _03ex01(void) { return compile_and_run("tests/c3e1.c", "ex01/ft_strncmp.c", "c3e1", 0); }
int _03ex02(void) { return compile_and_run("tests/c3e2.c", "ex02/ft_strcat.c", "c3e2", 0); }
int _03ex03(void) { return compile_and_run("tests/c3e3.c", "ex03/ft_strncat.c", "c3e3", 0); }
int _03ex04(void) { return compile_and_run("tests/c3e4.c", "ex04/ft_strstr.c", "c3e4", 0); }
int _03ex05(void) { return compile_and_run("tests/c3e5.c", "ex05/ft_strlcat.c", "c3e5", 0); }

int (*_03tests[])(void) = {
    _03ex00,
    _03ex01,
    _03ex02,
    _03ex03,
    _03ex04,
    _03ex05,
};

int libft_test03(void)
{
    int r;
    size_t nb_tests = sizeof(_03tests) / sizeof(_03tests[0]);

	r = system("norminette");
	if (r != 0)
	{
		libft_printf_err("\e[1;91m[X]\e[0m ERROR: Check the Norm\n");
		return (1);
	}
    for (size_t i = 0; i < nb_tests; i++)
    {
        char msg[64];
        snprintf(msg, sizeof(msg), "\e[1;93m[?]\e[0m Running tests for ex0%zu...\n", i);
        libft_putstr(msg);

        r = _03tests[i]();
        if (r != TESTPASSED)
        {
            libft_printf_err("\e[1;91m[ex0%d]: KO\e[0m\n", i);
            return r;
        }
		snprintf(msg, sizeof(msg), "\e[1;92m[+]\e[0m Tests for ex%02zu passed!\n\n\n", i);
        libft_putstr(msg);
    }
    return 0;
}
