/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:30:33 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/19 12:08:20 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prec_nbr(t_ptf **p)
{
	int		i;
	char	*r;

	i = (*p)->prec - (*p)->tmplen;
	if (i > 0)
	{
		r = ft_memalloc(sizeof(char) * (*p)->prec);
		r = ft_memset(r, '0', i);
		ft_memcpy(r + i, (*p)->tmp, (*p)->prec);
		(*p)->tmplen = (*p)->prec;
		free((*p)->tmp);
		(*p)->tmp = NULL;
		(*p)->tmp = ft_memdup(r, (*p)->prec);
		free(r);
		r = NULL;
	}
}

void	prec_str(t_ptf **p)
{
	char	*r;

	if ((*p)->tmplen - (*p)->prec > 0)
	{
		r = ft_memalloc(sizeof(char) * (*p)->prec);
		ft_memcpy(r, (*p)->tmp, (*p)->prec);
		(*p)->tmplen = (*p)->prec;
		free((*p)->tmp);
		(*p)->tmp = NULL;
		(*p)->tmp = ft_memdup(r, (*p)->prec);
		free(r);
		r = NULL;
	}
}
