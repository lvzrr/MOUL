/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_putnbr_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:57:53 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 00:58:05 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	libft_putnbr_err(int n)
{
	char	out;

	if (n == -2147483648)
	{
		write(2, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		libft_putnbr(n / 10);
	}
	out = '0' + (n % 10);
	write(2, &out, 1);
}
