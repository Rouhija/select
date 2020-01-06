/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:42:46 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/05 16:07:08 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		occurrences(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1 = ft_strstr(s1, s2)))
	{
		i++;
		s1 += ft_strlen(s2);
	}
	return (i);
}

static char		*ft_replace(t_ptf **p, char *org, char *rep, char *wth)
{
	int		i;
	char	*r;
	char	*tmp;
	char	*head;

	tmp = org;
	head = org;
	i = occurrences(tmp, rep);
	r = ft_strnew(ft_strlen(org) + (ft_strlen(wth) - ft_strlen(rep)) * i);
	while ((tmp = ft_strstr(tmp, rep)))
	{
		r = ft_strncat(r, org, ft_strlen(org) - ft_strlen(tmp));
		r = ft_strcat(r, wth);
		tmp += ft_strlen(rep);
		org = tmp;
	}
	r = ft_strjoin(r, ft_strdup(org));
	(*p)->len = ft_strlen(r);
	free(head);
	return (r);
}

void			parse_colors(t_ptf **p)
{
	if (ft_strstr((*p)->tmp, "{black}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{black}", BLACK);
	if (ft_strstr((*p)->tmp, "{red}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{red}", RED);
	if (ft_strstr((*p)->tmp, "{green}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{green}", GREEN);
	if (ft_strstr((*p)->tmp, "{yellow}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{yellow}", YELLOW);
	if (ft_strstr((*p)->tmp, "{blue}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{blue}", BLUE);
	if (ft_strstr((*p)->tmp, "{magneta}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{magneta}", MAGNETA);
	if (ft_strstr((*p)->tmp, "{cyan}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{cyan}", CYAN);
	if (ft_strstr((*p)->tmp, "{white}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{white}", WHITE);
	if (ft_strstr((*p)->tmp, "{normal}"))
		(*p)->tmp = ft_replace(p, (*p)->tmp, "{normal}", NORMAL);
}
