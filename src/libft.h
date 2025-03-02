#ifndef	H_LIBFT
#define H_LIBFT

#include <unistd.h>
#include <assert.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <glob.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/time.h>

#define TESTNUM 500000
#define TESTPASSED 0

typedef int (*t_func)(void);

int				libft_atoi(char *str);
int				libft_factorial(int n);
int				libft_power(int n, int x);
int				libft_iterative_power(int n, int x);
int				libft_strcmp(const char *s1, const char *s2);
int				libft_strlcat(char *dst, char *src, unsigned int size);
int				libft_strncmp(char *s1, char *s2, int size);
int				libft_fibonacci(int n);
int				libft_str_is_alpha(char *s);
int				libft_str_is_numeric(char *s);
int				libft_str_is_lowercase(char *s);
int				libft_str_is_uppercase(char *s);
int				libft_str_is_printable(char *s);
char			*libft_strcapitalize(char *str);
char			*libft_strncat(char *dst, char *src, unsigned int size);
char			*libft_strcat(char *dst, char *src);
char			*libft_gen_rand_str(unsigned int max_size);
void			libft_putchar(char c);
void			libft_print_err(char *str);
void			libft_printf(const char *str, ...);
void			libft_printf_err(const char *str, ...);
void			libft_putstr(char *str);
void			libft_putstr_err(char *str);
void			libft_putnbr(int nbr);
void			libft_putnbr_err(int nbr);
unsigned int	libft_strlen(char *src);
unsigned int	libft_strlcpy(char *dest, char *src, unsigned int size);

int				libft_test(t_func f[], unsigned int size);
int				compile_and_run(const char *tf, const char *ff, const char *ob, int nc);

int _01ex00(void);
int _01ex01(void);
int _01ex02(void);
int _01ex03(void);
int _01ex04(void);
int _01ex05(void);
int _01ex06(void);
int _01ex07(void);
int _01ex08(void);

extern t_func _01tests[];

int _02ex00(void);
int _02ex01(void);
int _02ex02(void);
int _02ex03(void);
int _02ex04(void);
int _02ex05(void);
int _02ex06(void);
int _02ex07(void);
int _02ex08(void);
int _02ex09(void);
int _02ex10(void);
int _02ex11(void);
int _02ex12(void);

extern t_func _02tests[];

int _03ex00(void);
int _03ex01(void);
int _03ex02(void);
int _03ex03(void);
int _03ex04(void);
int _03ex05(void);

extern t_func _03tests[];

int _04ex00(void);
int _04ex01(void);
int _04ex02(void);
int _04ex03(void);
int _04ex04(void);
int _04ex05(void);

extern t_func _04tests[];


int _05ex00(void);
int _05ex01(void);
int _05ex02(void);
int _05ex03(void);
int _05ex04(void);
int _05ex05(void);
int _05ex06(void);
int _05ex07(void);
int _05ex08(void);

extern t_func _05tests[];

#endif
