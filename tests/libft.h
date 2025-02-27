/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:07:30 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 00:07:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef	H_LIBFT
#define H_LIBFT

#include <unistd.h>
#include <assert.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <glob.h>

#define TESTNUM 1000000
#define TESTPASSED 0

int				libft_atoi(char *str);
int				libft_strcmp(const char *s1, const char *s2);
int				libft_strlcat(char *dst, char *src, unsigned int size);
int				libft_test01(void);
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

#endif
