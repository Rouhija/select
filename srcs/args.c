/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:23:56 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/12 14:39:18 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		free_arg(t_arg **arg)
{
	if (arg && *arg)
	{
		free((*arg)->name);
		free((*arg)->path);
		free((*arg)->color);
		free(*arg);
		(*arg) = NULL;
	}
}

void		free_memory(void)
{
	t_arg	*tmp;

	if (g_sel.active && g_sel.ac)
	{
		while (g_sel.active && g_sel.ac--)
		{
			tmp = g_sel.active->next;
			free_arg(&g_sel.active);
			if (g_sel.ac)
				g_sel.active = tmp;
		}
	}
}

t_arg		*new_arg(char *name)
{
	t_arg	*new;

	if (!(new = (t_arg *)ft_memalloc(sizeof(t_arg))))
		exit_program(3, 0);
	new->toggle = 0;
	new->name = ft_rfind(name, '/') ?
				ft_strdup(ft_rfind(name, '/') + 1) : ft_strdup(name);
	new->path = ft_rfind(name, '/') ?
				ft_strdup(name) : ft_strjoin("./", name);
	new->color = get_color(name);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

static void	insert_arg(char *name)
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
		g_sel.head = new;
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
		g_sel.max_w = (int)ft_strlen(av[i]) > g_sel.max_w ?
					(int)ft_strlen(av[i]) : g_sel.max_w;
		insert_arg(av[i]);
	}
}
