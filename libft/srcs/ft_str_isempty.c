/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isempty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:15:44 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/13 11:57:11 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Check if string consists of only whitespace characters.
** NULL argument returns 0.
*/

int		ft_str_isempty(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!ft_is_whitespace(s[i]))
			return (0);
		i++;
	}
	return (1);
}
