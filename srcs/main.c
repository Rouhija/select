/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/13 18:14:12 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			exit_program(int code, int flag)
{
	if (flag)
	{
		reset_config();
		free_memory();
	}
	code == 1 ? ft_putendl_fd(EXIT_1, 1) : PASS;
	code == 2 ? ft_putendl_fd(EXIT_2, 1) : PASS;
	code == 3 ? ft_putendl_fd(EXIT_3, 1) : PASS;
	code == 4 ? ft_putendl_fd(EXIT_4, 1) : PASS;
	code == 5 ? ft_putendl_fd(EXIT_5, 1) : PASS;
	code == 6 ? ft_putendl_fd(EXIT_6, 1) : PASS;
	code == 7 ? ft_putendl_fd(EXIT_7, 1) : PASS;
	exit(code);
}

int				main(int ac, char **av)
{
	if (ac < 2)
		exit_program(1, 0);
	monitor_signals();
	set_args(av);
	initial_config();
	wait_for_input();
	reset_config();
	print_selection();
	free_memory();
	return (0);
}
