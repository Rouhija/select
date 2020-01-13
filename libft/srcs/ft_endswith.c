/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 20:51:17 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/13 11:58:20 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endswith(const char *ends, char *with)
{
	int	i;

	if (!ends || !with)
		return (0);
	i = (int)(ft_strlen(ends) - ft_strlen(with));
	if (i < 0)
		return (0);
	return (ft_strequ(&ends[i], with));
}
