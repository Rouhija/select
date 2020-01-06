/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:34:37 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/03 16:35:51 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		if (n < len)
			write(1, s, n);
		else
			write(1, s, len);
	}
}
