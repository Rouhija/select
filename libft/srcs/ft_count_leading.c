/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_leading.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:30:56 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/19 18:25:35 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_leading_char_count(char const *s, int (*f)(int))
{
	size_t	i;

	i = 0;
	while (f(s[i]))
		i++;
	return (i);
}
