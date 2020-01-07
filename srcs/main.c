/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 22:29:11 by srouhe           ###   ########.fr       */
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
	code == 3 ? ft_putendl("ft_select: malloc error.") : PASS;
	exit(code);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		exit_program(NULL, 1, 0);
	signal(SIGINT, signal_handler);
	g_sel.av = av;
	set_args(av);
	ft_printf("cols %d rows %d max_w %d ac %d pad %d\n", g_sel.cols, g_sel.rows, g_sel.max_w, g_sel.ac, g_sel.pad);
	initial_config();
	wait_for_input();
	return (0);
}
