/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1e0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:02:11 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 16:20:42 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headtests.h"

int	main(void)
{
	int	c;
	int	p;
	int i;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		p = rand();
		i = p;
		ft_ft(&p);
		if (p != 42)
		{
			libft_printf_err("\n\t\tFAILED TEST:\n\t\t\tinput:\t%d\n\t\t\toutput:\t%d\n\n",i, 42);
			return (1);
		}
		c++;
	}
	return (TESTPASSED);
}
