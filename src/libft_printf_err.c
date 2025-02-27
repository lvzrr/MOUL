/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:55:35 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 00:56:20 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	libft_printf_err(const char *fmt, ...)
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
				libft_putstr_err(str);
			}
			else if (*fmt == 'd')
			{
				n = va_arg(args, int);
				libft_putnbr_err(n);
			}
			fmt++;
		}
	}
	va_end(args);
}
