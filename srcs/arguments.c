/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:56 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 23:02:09 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_arg		*new_arg(char *name)
{
	t_arg	*new;

	if (!(new = (t_arg *)ft_memalloc(sizeof(t_arg))))
		exit_program(NULL, 3, 0);
	new->toggle = 0;
	new->name = ft_rfind(name, '/') ? ft_strdup(ft_rfind(name, '/') + 1) : ft_strdup(name);
	new->format = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		insert_arg(char *name)
{
	t_arg	*new;
	t_arg	*tmp;

	new = new_arg(name);
	g_sel.ac++;
	if (!g_sel.args)
	{
		new->prev = new;
		new->next = new;
		g_sel.args = new;
		g_sel.active = new;
	}
	else
	{
		tmp = g_sel.args->prev;
		new->next = g_sel.args;
		g_sel.args->prev = new;	
		new->prev = tmp;
		tmp->next = new;
	}
}

void		set_args(char **av)
{
	int		i;
	
	i = 0;
	g_sel.x = 0;
	g_sel.y = 0;
	g_sel.ac = 0;
	g_sel.max_w = 0;
	while (av[++i])
	{
		g_sel.max_w = ft_strlen(av[i]) > g_sel.max_w ? ft_strlen(av[i]) : g_sel.max_w;
		insert_arg(av[i]);
	}
	column_count();
}

void		print_args(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g_sel.ac)
	{
		cursor_move(g_sel.x, g_sel.y);
		g_sel.x += g_sel.pad;
		if (g_sel.args == g_sel.active)
			ft_putstr_fd(UNDERLINE, 2);
		ft_putstr_fd(g_sel.args->name, 2);
		ft_putstr_fd(NORMAL, 2);
		j++;
		if (j == g_sel.cols)
		{
			j = 0;
			g_sel.y += 1;
			cursor_move(0, g_sel.y);
		}
		g_sel.args = g_sel.args->next;
		i++;
	}
	cursor_move(0, 0);
}