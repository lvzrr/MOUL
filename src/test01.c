#include "libft.h"

int _01ex00(void) { return compile_and_run("tests/c1e0.c", "ex00/ft_ft.c", "c1e0"); }
int _01ex01(void) { return compile_and_run("tests/c1e1.c", "ex01/ft_ultimate_ft.c", "c1e1"); }
int _01ex02(void) { return compile_and_run("tests/c1e2.c", "ex02/ft_swap.c", "c1e2"); }
int _01ex03(void) { return compile_and_run("tests/c1e3.c", "ex03/ft_div_mod.c", "c1e3"); }
int _01ex04(void) { return compile_and_run("tests/c1e4.c", "ex04/ft_ultimate_div_mod.c", "c1e4"); }
int _01ex05(void) { return compile_and_run("tests/c1e5.c", "ex05/ft_putstr.c", "c1e5"); }
int _01ex06(void) { return compile_and_run("tests/c1e6.c", "ex06/ft_strlen.c", "c1e6"); }
int _01ex07(void) { return compile_and_run("tests/c1e7.c", "ex07/ft_rev_int_tab.c", "c1e7"); }
int _01ex08(void) { return compile_and_run("tests/c1e8.c", "ex08/ft_sort_int_tab.c", "c1e8"); }

int (*_01tests[])(void) = {
    _01ex00,
    _01ex01,
    _01ex02,
    _01ex03,
    _01ex04,
    _01ex05,
    _01ex06,
    _01ex07,
    _01ex08
};

int libft_test01(void)
{
    int r;
    size_t nb_tests = sizeof(_01tests) / sizeof(_01tests[0]);

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

        r = _01tests[i]();
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
