/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:06:58 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 00:07:35 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	libft_printf(const char *fmt, ...)
{
	int				n;
	char			*str;
	va_list			args;

	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			write(1, fmt++, 1);
		else
		{
			fmt++;
			if (*fmt == 's')
			{
				str = va_arg(args, char *);
				libft_putstr(str);
			}
			else if (*fmt == 'd')
			{
				n = va_arg(args, int);
				libft_putnbr(n);
			}
			fmt++;
		}
	}
	va_end(args);
}
