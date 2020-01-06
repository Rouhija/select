/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:18:32 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/11 20:56:32 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** list of functions for argument formatting
*/

t_mod			g_tab[] =
{
	{HEX_PRE, &hex_prefix},
	{PRECNBR, &prec_nbr},
	{PRECSTR, &prec_str},
	{PADLEAD, &padding_leading},
	{PADTRAIL, &padding_trailing}
};

/*
** modification flags for numbers
*/

static void		mods_nbr(t_ptf **p)
{
	if ((*p)->c == 'p')
		(*p)->flags |= HEX_PRE;
	else if (((*p)->c == 'x' || (*p)->c == 'X') && (*p)->flags & F_HASH)
		(*p)->flags |= HEX_PRE;
	(*p)->flags |= (*p)->flags & PREC ? PRECNBR : NUL;
	if ((*p)->width)
		(*p)->flags |= (*p)->flags & F_MINUS ? PADTRAIL : PADLEAD;
}

/*
** modification flags for strings
*/

static void		mods_str(t_ptf **p)
{
	(*p)->flags |= (*p)->flags & PREC ? PRECSTR : NUL;
	if ((*p)->width)
		(*p)->flags |= (*p)->flags & F_MINUS ? PADTRAIL : PADLEAD;
}

/*
** pop out argument from stack, mark mod flags and perform mods
*/

void			format_argumet(t_ptf **p)
{
	int		i;

	if (ft_strchr("di", (*p)->c))
		(*p)->tmp = pop_signed(p);
	else if ((*p)->c == 's')
		(*p)->tmp = pop_string(p);
	else if (ft_strchr("ouxXpb", (*p)->c))
		(*p)->tmp = pop_unsigned(p);
	else if ((*p)->c == 'c')
		(*p)->tmp = pop_char(p);
	else if ((*p)->c == '%')
		(*p)->tmp = ft_memdup("%", 1);
	i = 0;
	(*p)->tmplen = ft_strlen((*p)->tmp);
	(*p)->c == 's' ? mods_str(p) : mods_nbr(p);
	while (i < 5)
	{
		g_tab[i].index & (*p)->flags ? g_tab[i].func(p) : PASS;
		i++;
	}
	fill_buffer(p);
}
