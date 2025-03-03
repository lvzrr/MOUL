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

	snprintf(full_test_file, sizeof(full_test_file), "%s%s", moul_dir, test_file);
	snprintf(full_lib_bin, sizeof(full_lib_bin), "%s/%s", lib_dir, "libft_*.o");
	snprintf(full_func_file, sizeof(full_func_file), "./%s", func_file);
	snprintf(full_output_bin, sizeof(full_output_bin), "%s/%s", out_dir, output_bin);

	w_trace("\e[1;93m[?]\e[0m Ensuring test file exists...\n");
	if (access(full_test_file, F_OK) == -1)
	{
		libft_printf_err("\n\t\t\e[1;91mNO TEST IMPLEMENTED\e[0m\n\n");
		return (1);
	}
	w_trace("\e[1;92m[+]\e[0m TEST FILE FOUND\n");
	w_trace("\e[1;93m[?]\e[0m Ensuring user file to evaluate exists...\n");
	if (access(full_func_file, F_OK) == -1)
	{
		libft_printf_err("\n\t\t\e[1;91mNO FILES FOUND\e[0m\n\n");
		return (1);
	}
	w_trace("\e[1;92m[+]\e[0m USER FILE FOUND\n");
	snprintf(python_command, sizeof(python_command), "python3 %sscripts/testheaders.py %d %s", moul_dir , n_cheat, func_file);
	w_trace("\e[1;93m[?]\e[0m STARTING PYTHON JOB: %s\n", python_command);
	result = system(python_command);
	if (WIFEXITED(result)) {
		int exit_status = WEXITSTATUS(result);
		switch (exit_status) {
			case 1:
				libft_printf_err("\n\t\t\e[1;91mCHEATS DETECTED\e[0m\n\n");
				return (2);
			case 2:
				libft_printf_err("\n\t\t\e[1;91mEXTRA FILES DETECTED\e[0m\n\n");
				return (2);
			default:
				break;
		}
	}
	w_trace("\e[1;92m[+]\e[0m NO CHEATS FOUND\n");
	size_t command_len = snprintf(command, sizeof(command),
		"cc -Wall -Wextra -Werror %s %s %s -o %s",
		full_test_file, full_func_file, full_lib_bin, full_output_bin);
	w_trace("\e[1;93m[?]\e[0m creating compilation command...\n");
	if (command_len >= sizeof(command))
	{
		libft_printf_err("error: command too long to fit in the buffer (compilation).\n");
		return (1);
	}
	w_trace("\e[1;93m[?]\e[0m COMPILING %s\n", command);
	result = system(command);
	if (result != 0)
	{
		libft_printf_err("error: compilation of %s failed.\n", func_file);
		return (1);
	}
	w_trace("\n\n\e[1;91m===========RUNNING FILE %s (%s)===========\e[0m\n\n", full_output_bin, full_func_file);
	result = system(full_output_bin);
	if (result != TESTPASSED)
	{
		libft_printf_err("error: running %s failed (if no failed tests its probably SEGFAULT)\n", full_output_bin);
		return (1);
	}
	w_trace("\n\n");
	w_trace("\e[1;93m[?]\e[0m Cleaning %s ...\n", full_output_bin);
	snprintf(rm_bin, sizeof(rm_bin), "rm %s/%s", out_dir, output_bin);
	if(system(rm_bin) != 0)
	{
		libft_printf_err("error: deleting %s failed.\n", full_output_bin);
		return (1);
	}
	w_trace("\e[1;92m[+]\e[0m Cleaned cache (%s)\n", full_output_bin);
	return (TESTPASSED);
}
