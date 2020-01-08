/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:01:39 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 20:56:18 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	initial_config(void)
{
	int		r;
	char	*term;
	char	buf[BUF_SIZE + 1];

	if (!isatty(2))
		exit_program(NULL, 4, 0);
	if (!(term = getenv("TERM")))
		exit_program(NULL, 7, 0);
	r = tgetent(buf, term);
	if (r == -1)
		exit_program(NULL, 5, 0);
	else if (r == 0)
		exit_program(NULL, 6, 0);
	tcgetattr(2, &g_sel.attr);
	tcgetattr(2, &g_sel.def);
	g_sel.attr.c_oflag &= ~OPOST;
	g_sel.attr.c_lflag &= ~(ECHO | ECHONL | ICANON);
	g_sel.attr.c_cc[VMIN] = 0;
	g_sel.attr.c_cc[VTIME] = 1;
	tcsetattr(2, TCSANOW, &g_sel.attr);
	tputs(CL, 1, printnbr);
	tputs(TI, 1, printnbr);
	tputs(VI, 1, printnbr);
}

void	reset_config(void)
{
	tcsetattr(2, TCSANOW, &g_sel.def);
	tputs(VE, 1, printnbr);
	tputs(TE, 1, printnbr);
}