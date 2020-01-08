/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:17:05 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 10:59:46 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_selection(void)
{
	int	i;
	int	spc;

	i = 0;
	spc = 0;
	while (i < g_sel.ac)
	{
		if (g_sel.args->toggle)
		{
			spc ? ft_putchar_fd(' ', 2) : PASS;
			ft_putstr_fd(g_sel.args->name, 2);
			spc = 1;
		}
		g_sel.args = g_sel.args->next;
		i++;
	}
	ft_putchar_fd('\n', 2);
}

void		print_args(void)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	while (i < g_sel.ac)
	{
		cursor_move(g_sel.x, g_sel.y);
		g_sel.y += 1;
		if (g_sel.args == g_sel.active)
			ft_putstr_fd(UNDERLINE, 2);
		if (g_sel.args->toggle)
			ft_putstr_fd(INVERSE_VIDEO, 2);
		// ft_putstr_fd(g_sel.args->name, 2);
		ft_putstr_fd(ft_itoa_base(g_sel.args->coord.x, 10), 2);
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(ft_itoa_base(g_sel.args->coord.y, 10), 2);
		ft_putstr_fd(NORMAL, 2);
		j++;
		if (j == g_sel.rows)
		{
			j = -1;
			g_sel.x += g_sel.pad;
			cursor_move(g_sel.x, 0);
		}
		g_sel.args = g_sel.args->next;
		i++;
	}
	cursor_move(0, 0);
}