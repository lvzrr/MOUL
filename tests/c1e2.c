/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1e2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:02:43 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 16:04:25 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headtests.h"

int	main(void)
{
	int	c;
	int	p1;
	int	p2;
	int	t1;
	int	t2;
	
	srand(time(NULL));
	c = 0;
	while (c < TESTNUM)
	{
		p1 = rand();
		p2 = rand();
		t1 = p1;
		t2 = p2;
		ft_swap(&p1, &p2);
		if (p1 != t2 || p2 != t1)
			return (0);
		c++;
	}
	return (TESTPASSED);
}

