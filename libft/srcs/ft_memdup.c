/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:11:15 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 18:00:11 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memdup(void const *src, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	void			*r;

	if (!(r = ft_memalloc(n + 1)))
		return (NULL);
	p1 = (unsigned char *)src;
	p2 = (unsigned char *)r;
	while (*p1 && n-- > 0)
		*p2++ = *p1++;
	*p2 = '\0';
	return (r);
}
