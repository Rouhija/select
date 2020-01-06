/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puchar_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:54:04 by srouhe            #+#    #+#             */
/*   Updated: 2019/11/14 15:59:06 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** for printing unicode
*/

static int		get_wchar_bytes(wint_t c)
{
	if (c < 0x007F)
		return (1);
	else if (c < 0x07FF)
		return (2);
	else if (c < 0xFFFF)
		return (3);
	else if (c < 0x10FFFF)
		return (4);
	return (0);
}

char			*ft_putchar_w(wint_t c)
{
	char	*wc;

	wc = ft_strnew(get_wchar_bytes(c));
	if (c <= 0x7F)
		wc[0] = c;
	else if (c <= 0x7FF)
	{
		wc[0] = (c >> 6) + 0xC0;
		wc[1] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0xFFFF)
	{
		wc[0] = (c >> 12) + 0xE0;
		wc[1] = ((c >> 6) & 0x3F) + 0x80;
		wc[2] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		wc[0] = (c >> 18) + 0xF0;
		wc[1] = ((c >> 12) & 0x3F) + 0x80;
		wc[2] = ((c >> 6) & 0x3F) + 0x80;
		wc[3] = (c & 0x3F) + 0x80;
	}
	return (wc);
}
