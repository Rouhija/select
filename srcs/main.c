/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 12:57:09 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		exit_program(char *arg, int code, int flag)
{
	if (flag)
		reset_config();
	code == 0 ? ft_putendl("ft_select: successful exit.") : PASS;
	code == 1 ? ft_putendl("usage: ./ft_select options") : PASS;
	code == 2 ? ft_putendl("ft_select: terminal configuration not found.") : PASS;
	exit(code);
}

int			column_count(int max_width)
{
	int				limit;
	int				cols;
	struct winsize	w;

	limit = 8;
	ioctl(1, TIOCGSIZE, &w);
	while (max_width >= limit)
		limit += 8;
	cols = w.ws_col / limit;
	return (cols);
}

void			print_args(void)
{
	int		i;
	int		j;
	int		x;
	int		cols;
	int		rows;

	g_sel.max_w = 0;
	rows = 0;
	i = 0;
	j = 0;
	x = 0;
	while (g_sel.av[++i])
		g_sel.max_w = ft_strlen(g_sel.av[i]) > g_sel.max_w ? ft_strlen(g_sel.av[i]) : g_sel.max_w;
	cols = column_count(g_sel.max_w);
	// ft_printf("columns %d max_w %d\n", cols, max_w);
	i = 0;
	while (g_sel.av[++i])
	{
		ft_putstr_fd(tgoto(CM, x, rows), 0);
		ft_putendl(g_sel.av[i]);
		x += g_sel.max_w + 8;
		j++;
		if (j == cols - 1)
		{
			rows++;
			x = 0;
			j = 0;
			ft_putstr_fd(tgoto(CM, 0, rows), 0);
		}
	}
	ft_putstr_fd(tgoto(CM, 0, 0), 0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		exit_program(NULL, 1, 0);
	signal(SIGINT, signal_handler);
	g_sel.av = av;
	initial_config();
	wait_for_input();
	return (0);
}
