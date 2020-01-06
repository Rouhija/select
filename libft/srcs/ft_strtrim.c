/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:53:40 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/18 16:50:33 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char			*r;
	size_t			size;
	unsigned int	beg;
	unsigned int	ws;

	if (!s)
		return (NULL);
	size = (size_t)ft_strlen(s);
	ws = ft_leading_char_count(s, ft_is_whitespace);
	beg = ws;
	if (size > ws)
		ws += ft_trailing_char_count(s, ft_is_whitespace);
	size -= ws;
	if (!s || !(r = ft_memalloc(size + 1)))
		return (NULL);
	r = ft_strncpy(r, s + beg, size);
	return (r);
}
