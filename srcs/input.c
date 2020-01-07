/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:56:18 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 23:04:12 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			action_arrow(long key)
{
	int	steps;

	steps = g_sel.cols;
	if (key == RIGHT)
		g_sel.active = g_sel.active->next;
	else if (key == LEFT)
		g_sel.active = g_sel.active->prev;
	else if (key == DOWN)
	{
		while (steps--)
			g_sel.active = g_sel.active->next;
	}
	else if (key == UP)
	{
		while (steps--)
			g_sel.active = g_sel.active->prev;
	}
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
			ft_putendl("ENTER");
		else if (key == SPC)
			ft_putendl("SPACE");
		else if (key == BKS)
			ft_putendl("BACKSPACE");
		else if (key == DEL)
			ft_putendl("DELETE");
		else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
			action_arrow(key);
	}
}