/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:56:18 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/10 15:29:49 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			wait_for_input(void)
{
	long		key;
	ssize_t		r;

	while (1)
	{
		key = 0;
		// tputs(CL, 1, printnbr);
		column_count(RETRY);
		print_args();
		if ((r = read(2, &key, 8)) < 1)
			continue ;
		if (key == ESC)
			exit_program(NULL, 0, 1);
		else if (key == ENT)
			break ;
		else if (key == A_UP || key == A_LO)
			action_all(key);
		else if (key == SPC)
			action_spc();
		else if (key == BKS || key == DEL)
			action_bks();
		else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
			action_arrow(key);
	}
}
