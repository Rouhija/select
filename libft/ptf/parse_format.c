/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:08:25 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/09 13:08:20 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Specify flags [#0-+ ]
*/

static void			flags(t_ptf **p)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAGS, (*p)->fptr[i]))
	{
		if ((*p)->fptr[i] == '#')
			(*p)->flags |= F_HASH;
		else if ((*p)->fptr[i] == '0')
			(*p)->flags |= F_ZERO;
		else if ((*p)->fptr[i] == '-')
			(*p)->flags |= F_MINUS;
		else if ((*p)->fptr[i] == ' ')
			(*p)->flags |= F_SPACE;
		else if ((*p)->fptr[i] == '+')
			(*p)->flags |= F_PLUS;
		i++;
	}
	(*p)->fptr += i;
}

/*
** Specify minimum field width
*/

static void			min_width(t_ptf **p)
{
	int		i;

	i = 0;
	if ((*p)->fptr[i] == '*')
	{
		(*p)->width = va_arg((*p)->ap, unsigned int);
		i++;
	}
	else if (((*p)->width = ft_atoi(&((*p)->fptr[i]))))
		i += ft_count_digits((*p)->width, 10);
	(*p)->fptr += i;
}

/*
** Specify precision
*/

static void			precision(t_ptf **p)
{
	int		i;

	i = 0;
	if ((*p)->fptr[i] == '.')
	{
		(*p)->flags |= PREC;
		i++;
		if ((*p)->fptr[i] == '*')
		{
			(*p)->prec = va_arg((*p)->ap, unsigned int);
			i++;
		}
		else
		{
			(*p)->prec = ft_atoi(&((*p)->fptr[i]));
			i += ft_count_digits((*p)->prec, 10);
		}
	}
	(*p)->fptr += i;
}

/*
** Specify length modifier [h, hh, l, ll, j, z]
*/

static void			len_modifier(t_ptf **p)
{
	int		i;

	i = 0;
	if ((*p)->fptr[i] == 'h' && (*p)->fptr[i + 1] == 'h')
		(*p)->flags |= L_HH;
	else if ((*p)->fptr[i] == 'h')
		(*p)->flags |= L_H;
	else if ((*p)->fptr[i] == 'l' && (*p)->fptr[i + 1] == 'l')
		(*p)->flags |= L_LL;
	else if ((*p)->fptr[i] == 'l')
		(*p)->flags |= L_L;
	else if ((*p)->fptr[i] == 'L')
		(*p)->flags |= L_LL;
	else if ((*p)->fptr[i] == 'j')
		(*p)->flags |= L_J;
	else if ((*p)->fptr[i] == 'z')
		(*p)->flags |= L_Z;
	if ((*p)->flags & L_HH || (*p)->flags & L_LL)
		i += 2;
	else if ((*p)->flags & L_H || (*p)->flags & L_L ||
			(*p)->flags & L_J || (*p)->flags & L_Z)
		i++;
	(*p)->fptr += i;
}

/*
** %[parameter][flags][width][.precision][length]type
** Check special cases in the end of the function.
*/

void				parse_format(t_ptf **p)
{
	int		i;

	i = 0;
	flags(p);
	min_width(p);
	precision(p);
	len_modifier(p);
	if ((*p)->flags & F_ZERO && !((*p)->flags & PREC) &&
		!((*p)->flags & F_MINUS))
		(*p)->padc = '0';
	(*p)->c = ft_strchr(CONVERSION, (*p)->fptr[i]) ? (*p)->fptr[i] : 0;
	(*p)->fptr += i + 1;
}
