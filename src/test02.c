#include "libft.h"

int _02ex00(void) { return compile_and_run("tests/c2e0.c", "ex00/ft_strcpy.c", 					"c2e0"); }
int _02ex01(void) { return compile_and_run("tests/c2e1.c", "ex01/ft_strncpy.c", 					"c2e1"); }
int _02ex02(void) { return compile_and_run("tests/c2e2.c", "ex02/ft_str_is_alpha.c", 				"c2e2"); }
int _02ex03(void) { return compile_and_run("tests/c2e3.c", "ex03/ft_str_is_numeric.c", 			"c2e3"); }
int _02ex04(void) { return compile_and_run("tests/c2e4.c", "ex04/ft_str_is_lowercase.c", 			"c2e4"); }
int _02ex05(void) { return compile_and_run("tests/c2e5.c", "ex05/ft_str_is_uppercase.c", 			"c2e5"); }
int _02ex06(void) { return compile_and_run("tests/c2e6.c", "ex06/ft_str_is_printable.c", 			"c2e6"); }
int _02ex07(void) { return compile_and_run("tests/c2e7.c", "ex07/ft_strupcase.c", 					"c2e7"); }
int _02ex08(void) { return compile_and_run("tests/c2e8.c", "ex08/ft_strlowcase.c", 				"c2e8"); }
int _02ex09(void) { return compile_and_run("tests/c2e9.c", "ex09/ft_strcapitalize.c",		 		"c2e9"); }
int _02ex10(void) { return compile_and_run("tests/c2e10.c", "ex10/ft_strlcpy.c", 					"c2e10"); }
int _02ex11(void) { return compile_and_run("tests/c2e11.c", "ex11/ft_putstr_non_printable.c", 		"c2e11"); }
int _02ex12(void) { return compile_and_run("tests/c2e12.c", "ex12/ft_print_memory.c", 				"c2e12"); }

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

int libft_test02(void)
{
    int r;
    size_t nb_tests = sizeof(_02tests) / sizeof(_02tests[0]);

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

        r = _02tests[i]();
        if (r != TESTPASSED)
        {
            libft_printf_err("\e[1;91m[ex0%d]: KO\e[0m\n", i);
            return r;
        }
		if (i < 10)
        	snprintf(msg, sizeof(msg), "\e[1;92m[+]\e[0m Tests for ex0%zu passed!\n\n\n", i);
		else 
        	snprintf(msg, sizeof(msg), "\e[1;92m[+]\e[0m Tests for ex%zu passed!\n\n\n", i);
        libft_putstr(msg);
    }
    return 0;
}
