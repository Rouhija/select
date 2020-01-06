/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 23:14:04 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/18 15:25:56 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c && !ft_strrchr(s + 1, c))
			return ((char *)s);
		s++;
		if (*s == c && !*s)
			return ((char *)s);
	}
	return (NULL);
}
