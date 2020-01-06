/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_w.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:56:21 by srouhe            #+#    #+#             */
/*   Updated: 2019/11/25 13:16:40 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_putstr_w(wchar_t *str)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = ft_putchar_w(*str);
	str++;
	while (*str)
	{
		ret = ft_strjoin(ret, ft_putchar_w(*str));
		str++;
	}
	return (ret);
}
