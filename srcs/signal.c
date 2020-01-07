/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:11:21 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 23:37:26 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT || signo == SIGKILL)
	{
		reset_config();
		exit_program(NULL, 0, 1);
	}
	else if (signo == SIGSTOP)
		ft_putendl_fd("Suspended", 2);
}
