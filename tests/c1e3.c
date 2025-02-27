/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1e3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:16:35 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 16:23:43 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headtests.h"

int	main(void)
{
	int	c;
	int	p1;
	int	p2;
	int	ptr1;
	int	ptr2;
	
	srand(time(NULL));
	c = 0;
	ptr1 = 0;
	ptr2 = 0;
	while (c < TESTNUM)
	{
		p1 = rand();
		p2 = rand();
		ft_div_mod(p1, p2, &ptr1, &ptr2);
		if (ptr1 != p1 / p2 || ptr2 != p1 % p2)
		{
			libft_printf_err("\n\t\tFAILED TEST:\n\t\t\tinput:\t%d, %d\n\t\t\toutput:\t%d, %d\n\n",p1,p2,ptr1,ptr2);
			return (1);
		}
		c++;
	}
	return (TESTPASSED);
}
