#include "libft.h"

int _01ex00(void) { return compile_and_run("tests/c1e0.c", "./ex00/ft_ft.c", "c1e0", 0); }
int _01ex01(void) { return compile_and_run("tests/c1e1.c", "./ex01/ft_ultimate_ft.c", "c1e1", 0); }
int _01ex02(void) { return compile_and_run("tests/c1e2.c", "./ex02/ft_swap.c", "c1e2", 0); }
int _01ex03(void) { return compile_and_run("tests/c1e3.c", "./ex03/ft_div_mod.c", "c1e3", 0); }
int _01ex04(void) { return compile_and_run("tests/c1e4.c", "./ex04/ft_ultimate_div_mod.c", "c1e4", 0); }
int _01ex05(void) { return compile_and_run("tests/c1e5.c", "./ex05/ft_putstr.c", "c1e5", 1); }
int _01ex06(void) { return compile_and_run("tests/c1e6.c", "./ex06/ft_strlen.c", "c1e6", 0); }
int _01ex07(void) { return compile_and_run("tests/c1e7.c", "./ex07/ft_rev_int_tab.c", "c1e7", 0); }
int _01ex08(void) { return compile_and_run("tests/c1e8.c", "./ex08/ft_sort_int_tab.c", "c1e8", 0); }

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

int _02ex00(void) { return compile_and_run("tests/c2e0.c", "ex00/ft_strcpy.c", "c2e0", 0); }
int _02ex01(void) { return compile_and_run("tests/c2e1.c", "ex01/ft_strncpy.c", "c2e1", 0); }
int _02ex02(void) { return compile_and_run("tests/c2e2.c", "ex02/ft_str_is_alpha.c", "c2e2", 0); }
int _02ex03(void) { return compile_and_run("tests/c2e3.c", "ex03/ft_str_is_numeric.c", "c2e3", 0); }
int _02ex04(void) { return compile_and_run("tests/c2e4.c", "ex04/ft_str_is_lowercase.c", "c2e4", 0); }
int _02ex05(void) { return compile_and_run("tests/c2e5.c", "ex05/ft_str_is_uppercase.c", "c2e5", 0); }
int _02ex06(void) { return compile_and_run("tests/c2e6.c", "ex06/ft_str_is_printable.c", "c2e6", 0); }
int _02ex07(void) { return compile_and_run("tests/c2e7.c", "ex07/ft_strupcase.c", "c2e7", 0); }
int _02ex08(void) { return compile_and_run("tests/c2e8.c", "ex08/ft_strlowcase.c", "c2e8", 0); }
int _02ex09(void) { return compile_and_run("tests/c2e9.c", "ex09/ft_strcapitalize.c", "c2e9", 0); }
int _02ex10(void) { return compile_and_run("tests/c2e10.c", "ex10/ft_strlcpy.c", "c2e10", 0); }
int _02ex11(void) { return compile_and_run("tests/c2e11.c", "ex11/ft_putstr_non_printable.c", "c2e11", 1); }
int _02ex12(void) { return compile_and_run("tests/c2e12.c", "ex12/ft_print_memory.c", "c2e12", 1); }

int (*_02tests[])(void) = {
    _02ex00,
    _02ex01,
    _02ex02,
    _02ex03,
    _02ex04,
    _02ex05,
    _02ex06,
    _02ex07,
    _02ex08,
	_02ex09,
	_02ex10,
	_02ex11,
	_02ex12
};

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

int libft_test(t_func tests[], unsigned int size)
{
    int r;
	r = system("norminette");
	if (r != 0)
	{
		libft_printf_err("\e[1;91m[X]\e[0m ERROR: Check the Norm\n");
		return (1);
	}
    for (size_t i = 0; i < size; i++)
    {
        char msg[64];
        snprintf(msg, sizeof(msg), "\e[1;93m[?]\e[0m Running tests for ex0%zu...\n", i);
        libft_putstr(msg);

        r = tests[i]();
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
