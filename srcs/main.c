/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/09 14:46:35 by srouhe           ###   ########.fr       */
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
	code == 0 ? ft_putendl_fd(EXIT_0, 2) : PASS;
	code == 1 ? ft_putendl_fd(EXIT_1, 2) : PASS;
	code == 2 ? ft_putendl_fd(EXIT_2, 2) : PASS;
	code == 3 ? ft_putendl_fd(EXIT_3, 2) : PASS;
	code == 4 ? ft_putendl_fd(EXIT_4, 2) : PASS;
	code == 5 ? ft_putendl_fd(EXIT_5, 2) : PASS;
	code == 6 ? ft_putendl_fd(EXIT_6, 2) : PASS;
	code == 7 ? ft_putendl_fd(EXIT_7, 2) : PASS;
	exit(code);
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
	return (0);
}
