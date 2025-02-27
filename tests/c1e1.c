/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1e1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:04:31 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/27 16:04:31 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headtests.h"

int main(void) 
{
	srand(time(NULL));
	int	c;

	c = 0;
	while (c < TESTNUM)
	{
		int value = rand();
		int *p1 = &value;
		int **p2 = &p1;
		int ***p3 = &p2;
		int ****p4 = &p3;
		int *****p5 = &p4;
		int ******p6 = &p5;
		int *******p7 = &p6;
		int ********p8 = &p7;
		int *********p9 = &p8;
		ft_ultimate_ft(p9);
		if (*********p9 != 42)
			return (1);
		c++;
	}
    return (0);
}
