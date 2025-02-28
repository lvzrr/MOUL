/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaicastr <jaicastr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:28:59 by jaicastr          #+#    #+#             */
/*   Updated: 2025/02/25 11:29:14 by jaicastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	libft_ctype(char c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= '0' && c <= '9')
		return (2);
	else
		return (3);
}

void	libft_change(int t, char *c, int *i_w)
{
	if (!*i_w && t == 0)
	{
		*c -= ('a' - 'A');
		*i_w = 1;
	}
	else if (*i_w && t == 1)
		*c -= ('A' - 'a');
	else if (i_w && t == 3)
		*i_w = 0;
	else if (!*i_w && t < 3)
		*i_w = 1;
}

char	*libft_strcapitalize(char *str)
{
	int		i_w;
	char	*r;

	i_w = 0;
	r = str;
	while (*str)
	{
		libft_change(libft_ctype(*str), str, &i_w);
		str++;
	}
	return (r);
}
