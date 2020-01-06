/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/18 14:20:43 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		padding_leading(t_ptf **p)
{
	int		i;
	char	*r;

	i = (*p)->width - (*p)->tmplen;
	if (i > 0)
	{
		if (!(r = ft_strnew((*p)->width)))
			return ;
		r = ft_memset(r, (*p)->padc, i);
		ft_memcpy(r + i, (*p)->tmp, (*p)->tmplen);
		(*p)->tmplen = (*p)->width;
		free((*p)->tmp);
		(*p)->tmp = NULL;
		(*p)->tmp = ft_strdup(r);
		free(r);
		r = NULL;
	}
}

void		padding_trailing(t_ptf **p)
{
	int		i;
	char	*r;

	i = (*p)->width - (*p)->tmplen;
	if (i > 0)
	{
		if (!(r = ft_strnew((*p)->width)))
			return ;
		r = ft_memset(r, (*p)->padc, (*p)->width);
		ft_memcpy(r, (*p)->tmp, (*p)->tmplen);
		(*p)->tmplen = (*p)->width;
		free((*p)->tmp);
		(*p)->tmp = NULL;
		(*p)->tmp = ft_strdup(r);
		free(r);
		r = NULL;
	}
}
