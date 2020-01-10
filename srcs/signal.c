/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 15:11:21 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/10 20:21:58 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	Signals:
**		SIGINT:		^C
**		SIGQUIT:	^\
**		SIGTSTP:	^Z
**		SIGSTOP:	^S
**		SIGCONT:	^Q
**		SIGWINCH:	Screen resizing
*/

void	monitor_signals(void)
{
	signal(SIGSTOP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGWINCH, signal_handler);
}

void	signal_handler(int signo)
{
	if (signo == SIGTSTP)
	{
		reset_config();
		signal(SIGTSTP, SIG_DFL);
		ioctl(OUTPUT, TIOCSTI, CTRL_Z);
	}
	else if (signo == SIGCONT)
	{
		initial_config();
		monitor_signals();
		print_args();
	}
	else if (signo == SIGINT || signo == SIGKILL ||
		signo == SIGSTOP || signo == SIGQUIT)
	{
		reset_config();
		exit_program(NULL, 0, 1);
	}
	else if (signo = SIGWINCH)
	{
		tputs(CL, 1, printnbr);
		print_args();
	}
}
