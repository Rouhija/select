/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:34:29 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/18 16:07:27 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (alst && *alst)
	{
		while (*alst)
		{
			tmp = *alst;
			del(tmp->content, tmp->content_size);
			*alst = (*alst)->next;
			free(tmp);
			tmp = NULL;
		}
	}
}
