#include "test.h"

#undef TESTNUM
#define TESTNUM 100000

int main(void)
{
    srand(time(NULL));
    char test_str[101];
    int c2e4_result;
	int libft_result;
    
    for (int test = 0; test < TESTNUM; test++) {
        int len = rand() % 100;
        
        for (int i = 0; i < len; i++) {
            int char_type = rand() % 4;
            
            if (char_type == 0) {
                test_str[i] = 'a' + (rand() % 26);
            } else if (char_type == 1) {
                test_str[i] = 'A' + (rand() % 26);
            } else if (char_type == 2) {
                test_str[i] = '0' + (rand() % 10);
            } else {
                int ascii;
                do {
                    ascii = 33 + (rand() % 94);
                } while ((ascii >= 'a' && ascii <= 'z') || 
                         (ascii >= 'A' && ascii <= 'Z') || 
                         (ascii >= '0' && ascii <= '9'));
                test_str[i] = (char)ascii;
            }
        }
        test_str[len] = '\0';
        
        libft_result = libft_str_is_uppercase(test_str);
        c2e4_result = ft_str_is_uppercase(test_str);
        
        if (c2e4_result != libft_result) {
            libft_printf_err("\n\t\t\e[1;91mFAILED TEST\e[0m\n\t\t\texpected: %d\n\t\t\tgot: %d\n\t\t\tstr: %s\n\n", libft_result, c2e4_result, test_str);
            return 1;
        }
    }
    
    return 0;
}
