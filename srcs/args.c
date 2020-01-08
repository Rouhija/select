/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:56 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 10:29:45 by srouhe           ###   ########.fr       */
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

void	free_args(void) /* not working */
{
	t_arg	*tmp;

	while (g_sel.args != NULL)
	{
		free(g_sel.args->name);
		tmp = g_sel.args->next;
		free(g_sel.args);
		g_sel.args = tmp;
	}
}

static void	insert_arg(char *name)
{
	t_arg	*new;
	t_arg	*tmp;

	new = new_arg(name);
	new->column = 0;
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

void		delete_arg(void)
{
	t_arg	*prev;
	t_arg	*next;

	prev = g_sel.active->prev;
	next = g_sel.active->next;
	free(g_sel.active);
	g_sel.ac--;
	g_sel.active = next;
	// free_args();
	prev->next = next;
	next->prev = prev;
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