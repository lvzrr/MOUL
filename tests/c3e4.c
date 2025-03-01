#include "test.h"

	int main() {
		srand(time(NULL));
		int c = 0;

		while (c < TESTNUM) {
			char *haystack = (char *)malloc(101 * sizeof(char));
			if (haystack == NULL) {
				libft_printf_err("Memory allocation failed\n");
				return (1);
			}

			int l = (rand() % 47) + 4;
			int c2 = 0;
			while (c2 < l)
				haystack[c2++] = ' ' + rand() % 95;
			haystack[c2] = '\0';

			int needle_start_pos = rand() % (l - 3);
			char *needle = haystack + needle_start_pos;

			int needle_len = 3 + rand() % (l - needle_start_pos - 2);

			if (needle_start_pos + needle_len > l) {
				libft_printf_err("Invalid needle size: %d, haystack length: %d\n", needle_len, l);
				free(haystack);
				return (1);
			}

			if (haystack[l] != '\0') {
				libft_printf_err("Haystack is not null-terminated properly at position %d\n", l);
				free(haystack);
				return (1);
			}

			char *got = ft_strstr(haystack, needle);

			if (libft_strcmp(needle, got) != 0) {
				libft_printf_err("\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %s\n\t\t\tgot: %s\n\t\t\thaystack:  %s\n\n", needle, got, haystack);
				free(haystack);
				return (1);
			}

			free(haystack);
			c++;
		}

		return (0);
	}
