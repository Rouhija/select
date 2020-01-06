/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isempty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:15:44 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/05 18:39:47 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_isempty(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (!ft_is_whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}
