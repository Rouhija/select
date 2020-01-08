/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 21:13:34 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			exit_program(char *arg, int code, int flag)
{
	if (flag)
	{
		reset_config();
		free_memory();
	}
	code == 0 ? ft_putendl_fd("ft_select: successful exit.", 2) : PASS;
	code == 1 ? ft_putendl_fd("usage: ./ft_select options", 2) : PASS;
	code == 2 ? ft_putendl_fd("ft_select: terminal configuration not found.", 2) : PASS;
	code == 3 ? ft_putendl_fd("ft_select: malloc error.", 2) : PASS;
	code == 4 ? ft_putendl_fd("ft_select: incorrect environment.", 2) : PASS;
	code == 5 ? ft_putendl_fd("ft_select: termcaps database not found.", 2) : PASS;
	code == 6 ? ft_putendl_fd("ft_select: terminal not found in termcaps database.", 2) : PASS;
	code == 7 ? ft_putendl_fd("ft_select: TERM environment value not found.", 2) : PASS;
	exit(code);
}

static void		monitor_signals(void)
{
	signal(SIGSTOP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTSTP, signal_handler);
}

int				main(int ac, char **av)
{
	if (ac < 2)
		exit_program(NULL, 1, 0);
	monitor_signals();
	set_args(av);
	// ft_printf("cols %d rows %d max_w %d ac %d pad %d active column %d lacking %d\n", g_sel.cols, g_sel.rows, g_sel.max_w, g_sel.ac, g_sel.pad, g_sel.active->column, g_sel.lacking);
	initial_config();
	wait_for_input();
	reset_config();
	print_selection();
	free_memory();
	/* Print selected arguments back to terminal and restore default and free memory */
	return (0);
}
