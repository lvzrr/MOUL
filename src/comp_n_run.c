#include "libft.h"

int compile_and_run(const char *test_file, const char *func_file, const char *output_bin, int n_cheat)
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

	char python_command[1024];

	snprintf(python_command, sizeof(python_command), "python3 %sscripts/testheaders.py %d %s", moul_dir , n_cheat, func_file);
	result = system(python_command);

	if (result != 0)
	{
		libft_printf_err("\n\t\t\e[1;91mCHEATS DETECTED\e[0m\n\n");
		return (2);
	}

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
	libft_printf("\tcompiling...\r");
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
	if(system(rm_bin) != 0)
	{
		libft_printf_err("error: deleting %s failed.\n", full_output_bin);
		return (2);
	}
	return (TESTPASSED);
}
