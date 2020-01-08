/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:56:18 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 20:12:12 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			wait_for_input(void)
{
	long		key;

	while (1)
	{
		key = 0;
		print_args();
		read(2, &key, 8);
		if (key == ESC)
			exit_program(NULL, 0, 1);
		else if (key == ENT)
			break ;
		else if (key == SPC)
			action_spc();
		else if (key == BKS || key == DEL)
		{
			action_bks();
			tputs(CL, 1, printnbr);
		}
		else if (key == UP || key == DOWN || key == RIGHT || key == LEFT)
			action_arrow(key);
		if (((key == BKS || key == DEL) && !g_sel.ac))
			exit_program(NULL, 0, 1);
	}
}