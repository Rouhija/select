/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:56:18 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 12:56:57 by srouhe           ###   ########.fr       */
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
			ft_putendl("ENTER");
		else if (key == SPC)
			ft_putendl("SPACE");
		else if (key == BKS)
			ft_putendl("BACKSPACE");
		else if (key == DEL)
			ft_putendl("DELETE");
		else if (key == UP)
			ft_putendl("UP");
		else if (key == DOWN)
			ft_putendl("DOWN");
		else if (key == RIGHT)
			ft_putendl("RIGHT");
		else if (key == LEFT)
			ft_putendl("LEFT");
	}
}