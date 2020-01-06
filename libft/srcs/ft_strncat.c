/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:50:54 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/19 12:25:21 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s2[i])
		return (s1);
	while (s1[j])
		j++;
	while (s2[i] && i < n)
	{
		s1[j + i] = (char)s2[i];
		i++;
	}
	s1[j + i] = '\0';
	return (s1);
}
