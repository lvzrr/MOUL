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

int _04ex00(void) { return compile_and_run("tests/c4e0.c", "ex00/ft_strlen.c", "c4e0", 0); }
int _04ex01(void) { return compile_and_run("tests/c4e1.c", "ex01/ft_putstr.c", "c4e1", 1); }
int _04ex02(void) { return compile_and_run("tests/c4e2.c", "ex02/ft_putnbr.c", "c4e2", 1); }
int _04ex03(void) { return compile_and_run("tests/c4e3.c", "ex03/ft_atoi.c", "c4e3", 0); }
int _04ex04(void) { return compile_and_run("tests/c4e4.c", "ex04/ft_putnbr_base.c", "c4e4", 1); }
int _04ex05(void) { return compile_and_run("tests/c4e5.c", "ex05/ft_atoi_base", "c4e5", 0); }

int (*_04tests[])(void) = {
_04ex00,
_04ex01,
_04ex02,
_04ex03,
_04ex04,
_04ex05,
};

void print_summary(int grade, struct timeval start_time, int size)
{
	struct timeval end_time;
	gettimeofday(&end_time, NULL);
	double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
	                      (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

	libft_printf("\n+--------------- SUMMARY ---------------+\n");
	printf("Total Runtime: %.4f seconds\n", elapsed_time);
	fflush(stdout);
	libft_printf("Total Tests: %d\n", TESTNUM * size);
	if (grade >= 50)
		libft_printf("\e[42;30m Final Grade: %d \e[0m\n\n", grade);
	else
		libft_printf("\e[41;30m Final Grade: %d \e[0m\n\n", grade);
}

int libft_test(t_func tests[], unsigned int size)
{
	int r;
	int grade = 0;
	struct timeval start_time;
	gettimeofday(&start_time, NULL);
	libft_printf("\n\n\e[1;93m[?]\e[0m RUNNING NORMINETTE\n\n");
	r = system("norminette");
	if (r != 0)
	{
		libft_printf_err("\e[1;91m[X]\e[0m ERROR: Check the Norm\n");
		return (1);
	}
	libft_printf("\n\n\e[1;92m[+] PASSED NORMINETTE\e[0m\n\n");
	for (size_t i = 0; i < size; i++)
	{
		char msg[64];
		snprintf(msg, sizeof(msg), "\e[1;93m[?]\e[0m Running ex%02zu...\r",i);
		printf(msg);
		fflush(stdout);

		r = tests[i]();
		if (r == 1)
		{
			libft_printf_err("\e[1;91m[ex0%d]: KO\e[0m\n", i);
			print_summary(grade, start_time, size);
			return (1);
		}
		else if (r == 2)
		{
			grade = -42;
			print_summary(grade, start_time, size);
			return (1);
		}
		else
		{
			snprintf(msg, sizeof(msg), "\e[1;92m[+]\e[0m Tests for ex%02zu passed!\n\n\n", i);
			printf(msg);
			fflush(stdout);
			grade += (100 / size);
		}
	}
	print_summary(grade, start_time, size);
	return 0;
}
