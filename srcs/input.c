/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:56:18 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 10:57:58 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			action_arrow(long key)
{
	int	steps;

	steps = g_sel.rows + 1;
	if (g_sel.active->column == g_sel.cols && key == RIGHT)
		steps -= (g_sel.cols * (g_sel.rows + 1)) % g_sel.ac;
	else if (g_sel.active->coord.x == 1 && key == LEFT)
		steps -= (g_sel.cols * (g_sel.rows + 1)) % g_sel.ac;
	if (key == DOWN)
		g_sel.active = g_sel.active->next;
	else if (key == UP)
		g_sel.active = g_sel.active->prev;
	else if (key == RIGHT)
	{
		while (steps--)
			g_sel.active = g_sel.active->next;
	}
	else if (key == LEFT)
	{
		while (steps--)
			g_sel.active = g_sel.active->prev;
	}
}

void			action_spc(void)
{
	g_sel.active->toggle = g_sel.active->toggle ? 0 : 1;
	action_arrow(RIGHT);
}

void			wait_for_input(void)
{
	long		key;

	while (1)
	{
		key = 0;
		print_args();
		read(2, &key, 8);
		if (key == ESC)
			exit_program(NULL, 0, 1);
		else if (key == ENT)
			break ;
		else if (key == SPC)
			action_spc();
		else if (key == BKS || key == DEL)
			delete_arg();
		else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
			action_arrow(key);
	}
}