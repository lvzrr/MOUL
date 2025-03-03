#include "test.h"

int main() {
	srand(time(NULL));
	int c = 0;
	while (c < TESTNUM) {
		int l = rand() % 100;
		char *str = (char *)malloc((l + 1) * sizeof(char));
		if (str == NULL) {
		perror("malloc failed");
		return 1;
		}
		for (int i = 0; i <= l; i++) {
		str[i] = '0';
		}
		str[l] = '\0';
		int c2 = 0;
		int spacelen = (l > 0) ? rand() % (l / 4 + 1) : 0;
		int signlen = (l > 0) ? rand() % (l / 4 + 1) : 0;
		int letterlen = (l > 0) ? rand() % (l / 4 + 1) : 0;
		int space_count = 0, sign_count = 0, num_count = 0, letter_count = 0;
		while (c2 < l)
		{
			if (space_count < spacelen) {
				str[c2++] = ' ';
				space_count++;
			} else if (sign_count < signlen) {
				str[c2++] = (rand() % 2 == 0) ? '+' : '-';
				sign_count++;
			} else if (num_count < 7) {
				str[c2++] = '0' + (rand() % 10);
				num_count++;
			} else if (letter_count < letterlen) {
				str[c2++] = 'a' + (rand() % 26);
				letter_count++;
			} else {
				break;
			}
		}
		str[c2] = '\0';
		int result = ft_atoi(str);
		int unit = libft_atoi(str);
		if (c % 100000 == 0)
			w_trace("Str: %s\nResult: %d (expected %d)\n", str, result, unit);
		if (result != unit) {
		libft_printf_err(
			"\n\t\t\e[1;91mTEST FAILED\e[0m:\n\t\t\texpected: %d\n\t\t\tgot: "
			"%d\n\t\t\tstr:  %s\n\n",
			result, unit, str);
		free(str);
		return (1);
		}
		free(str);
		c++;
	}
	return 0;
}
