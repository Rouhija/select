/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:33:45 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 18:43:15 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		action_bks(void)
{
	t_arg	*prev;
	t_arg	*next;
	t_arg	*tmp;

	prev = g_sel.active->prev;
	next = g_sel.active->next;
	g_sel.ac--;
	tmp = g_sel.active;
	free_arg(&tmp);
	g_sel.active = next;
	prev->next = next;
	next->prev = prev;
	tputs(CL, 1, printnbr);
}

void			action_arrow(long key)
{
	int	steps;

	steps = g_sel.rows ? step_count(key) : g_sel.rows + 1;
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