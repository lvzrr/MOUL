/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:07:33 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 00:07:34 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	main(int argc, char **argv)
{
	int	level;

	if (argc < 2)
		return (1);
	level = libft_atoi(argv[1]);
	if (level == 1)
		return libft_test01();

	return (0);
}
