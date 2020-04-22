/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 23:17:05 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/13 20:41:34 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select.h"

static void		print_header(void)
{
	char	*objs;
	char	*sel;

	objs = ft_itoa_base(g_sel.ac, 10);
	sel = ft_itoa_base(g_sel.selected, 10);
	// ft_putstr_fd(WHITE, OUTPUT);
	ft_putstr_fd(tgoto(CM, 0, 0), 0);
	// ft_putstr_fd("**** SELECT ****", OUTPUT);
	ft_putstr_fd("ENTER:   confirm    | SPACE:   select/unselect | DEL: remove from list", OUTPUT);
	ft_putstr_fd(tgoto(CM, 0, 1), 0);
	// ft_putstr_fd(WHITE, OUTPUT);
	// ft_putstr_fd("relative path: ", OUTPUT);
	ft_putstr_fd("SHIFT+A: select all | SHIFT+Z: unselect all    | ESC: exit", OUTPUT);
	ft_putstr_fd(tgoto(CM, 0, 2), 0);
	tputs(CE, 1, printnbr);
	ft_putstr_fd(g_sel.active->name, OUTPUT);
	ft_putstr_fd(tgoto(CM, 0, 3), 0);
	tputs(CE, 1, printnbr);
	ft_putstr_fd("objects: ", OUTPUT);
	ft_putstr_fd(objs, OUTPUT);
	ft_putstr_fd(" selected: ", OUTPUT);
	ft_putstr_fd(sel, OUTPUT);
	// ft_putstr_fd(NORMAL, OUTPUT);
	free(objs);
	free(sel);
}

static void		print_out(void)
{
	if (g_sel.args == g_sel.active)
		ft_putstr_fd(UNDERLINE, OUTPUT);
	if (g_sel.args->toggle)
	{
		ft_putstr_fd(INVERSE_VIDEO, OUTPUT);
		g_sel.selected++;
	}
	// ft_putstr_fd(g_sel.args->color, OUTPUT);
	// if (ft_endswith(g_sel.args->name, ".o") ||
	// 	ft_endswith(g_sel.args->name, ".c"))
	// 	ft_printf(OUTPUT, "\e[3m%s\e[0m", g_sel.args->name);
	// else
	ft_putstr_fd(g_sel.args->name, OUTPUT);
	ft_putstr_fd(NORMAL, OUTPUT);
}

void			print_selection(void)
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
			ft_putstr_fd(g_sel.args->name, 1);
			flag = 1;
		}
		g_sel.args = g_sel.args->next;
		i++;
	}
	flag ? ft_putchar_fd('\n', 1) : PASS;
}

void			print_args(void)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!column_count())
		return ;
	g_sel.selected = 0;
	while (++i < g_sel.ac)
	{
		cursor_move(g_sel.x, g_sel.y);
		g_sel.y += 1;
		print_out();
		j++;
		if (j == g_sel.rows)
		{
			j = -1;
			g_sel.x += g_sel.pad;
			cursor_move(g_sel.x, 0);
		}
		g_sel.args = g_sel.args->next;
	}
	print_header();
	cursor_move(0, 0);
}
