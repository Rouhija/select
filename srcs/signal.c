/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:11:21 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 21:18:32 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	signal_handler(int signo)
{
	if (signo == SIGINT || signo == SIGKILL || signo == SIGABRT || signo == SIGSTOP || signo == SIGQUIT)
	{
		reset_config();
		exit_program(NULL, 0, 1);
	}
	else if (signo == SIGSTOP)
	{
		reset_config();
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
}
