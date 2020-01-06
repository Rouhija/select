/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_trailing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:32:13 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/19 18:25:39 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_trailing_char_count(char const *s, int (*f)(int))
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (s[i])
		i++;
	i--;
	while (f(s[i]))
	{
		i--;
		c++;
	}
	return (c);
}
