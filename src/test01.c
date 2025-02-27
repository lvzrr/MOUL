#include "libft.h"

int compile_and_run(const char *test_file, const char *func_file, const char *output_bin)
{
	char command[1024];
	int result;
	const char *moul_dir = getenv("MOUL");
	const char *out_dir = getenv("MOUL_TEST_BIN");
	const char *lib_dir = getenv("MOUL_BIN");

	if (moul_dir == NULL)
	{
		libft_printf_err("error: moul environment variable is not set.\n");
		return (1);
	}

	char full_test_file[512];
	char full_func_file[512];
	char full_output_bin[512];
	char full_lib_bin[512];
	char rm_bin[512];

	snprintf(full_test_file, sizeof(full_test_file), "%s%s", moul_dir, test_file);
	snprintf(full_lib_bin, sizeof(full_lib_bin), "%s/%s", lib_dir, "libft_*.o");
	snprintf(full_func_file, sizeof(full_func_file), "./%s", func_file);
	snprintf(full_output_bin, sizeof(full_output_bin), "%s/%s", out_dir, output_bin);

	size_t command_len = snprintf(command, sizeof(command),
		"cc -Wall -Wextra -Werror %s %s %s -o %s",
		full_test_file, full_func_file, full_lib_bin, full_output_bin);
	if (command_len >= sizeof(command))
	{
		libft_printf_err("error: command too long to fit in the buffer (compilation).\n");
		return (1);
	}
	libft_printf("\tcompiling: %s\n", command);
	result = system(command);
	if (result != 0)
	{
		libft_printf_err("error: compilation of %s failed.\n", func_file);
		return (1);
	}
	libft_printf("\trunning: %s\n", full_output_bin);
	result = system(full_output_bin);
	if (result != TESTPASSED)
	{
		libft_printf_err("error: running %s failed.\n", full_output_bin);
		return (2);
	}
	snprintf(rm_bin, sizeof(rm_bin), "rm %s/%s", out_dir, output_bin);
	system(rm_bin);
	return (TESTPASSED);
}


int ex00(void) { return compile_and_run("tests/c1e0.c", "ex00/ft_ft.c", "c1e0"); }
int ex01(void) { return compile_and_run("tests/c1e1.c", "ex01/ft_ultimate_ft.c", "c1e1"); }
int ex02(void) { return compile_and_run("tests/c1e2.c", "ex02/ft_swap.c", "c1e2"); }
int ex03(void) { return compile_and_run("tests/c1e3.c", "ex03/ft_div_mod.c", "c1e3"); }
int ex04(void) { return compile_and_run("tests/c1e4.c", "ex04/ft_ultimate_div_mod.c", "c1e4"); }
int ex05(void) { return compile_and_run("tests/c1e5.c", "ex05/ft_putstr.c", "c1e5"); }
int ex06(void) { return compile_and_run("tests/c1e6.c", "ex06/ft_strlen.c", "c1e6"); }
int ex07(void) { return compile_and_run("tests/c1e7.c", "ex07/ft_rev_int_tab.c", "c1e7"); }
int ex08(void) { return compile_and_run("tests/c1e8.c", "ex08/ft_sort_int_tab.c", "c1e8"); }

int (*tests[])(void) = {
    ex00,
    ex01,
    ex02,
    ex03,
    ex04,
    ex05,
    ex06,
    ex07,
    ex08
};

int libft_test01(void)
{
    int r;
    size_t nb_tests = sizeof(tests) / sizeof(tests[0]);

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

        r = tests[i]();
        if (r != TESTPASSED)
        {
            libft_printf_err("[ex0%d]: KO\n", i);
            return r;
        }
        snprintf(msg, sizeof(msg), "\e[1;92m[+]\e[0m Tests for ex0%zu passed!\n\n\n", i);
        libft_putstr(msg);
    }
    return 0;
}
