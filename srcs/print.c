/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:17:05 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 20:54:23 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		print_selection(void)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < g_sel.ac)
	{
		if (g_sel.args->toggle)
		{
			flag ? ft_putchar_fd(' ', 1) : PASS;
			ft_putstr_fd(g_sel.args->path, 1);
			flag = 1;
		}
		g_sel.args = g_sel.args->next;
		i++;
	}
	flag ? ft_putchar_fd('\n', 1) : PASS;
}

void		print_header(void)
{
	ft_putstr_fd(WHITE, 2);
	ft_putstr_fd(tgoto(CM, 0, 0), 0);
	ft_putstr_fd("FT_SELECT BY ", 2);
	ft_putstr_fd(ft_strupper(getenv("USER")), 2);
	ft_putstr_fd(tgoto(CM, 0, 1), 0);
	// tputs(CE, 1, printnbr);
	ft_putstr_fd("                                                     ", 2);
	ft_putstr_fd(tgoto(CM, 0, 1), 0);
	ft_putstr_fd("relative path: ", 2);
	ft_putstr_fd(g_sel.active->path, 2);
	ft_putstr_fd(NORMAL, 2);
}

void		print_args(void)
{
	int		i;
	int		j;

	i = 0;
	j = -1;
	column_count();
	print_header();
	g_sel.args = g_sel.head;
	while (i < g_sel.ac)
	{
		cursor_move(g_sel.x, g_sel.y);
		g_sel.y += 1;
		if (g_sel.args == g_sel.active)
			ft_putstr_fd(UNDERLINE, 2);
		if (g_sel.args->toggle)
			ft_putstr_fd(INVERSE_VIDEO, 2);
		ft_putstr_fd(g_sel.args->color, 2);
		ft_putstr_fd(g_sel.args->name, 2);
		// ft_putstr_fd(ft_itoa_base(g_sel.args->coord.x, 10), 2);
		// ft_putchar_fd(' ', 2);
		// ft_putstr_fd(ft_itoa_base(g_sel.args->coord.y, 10), 2);
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