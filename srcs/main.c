/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 00:17:29 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

int		main(int ac, char **av)
{
	int				r;
	char			buf[BUF_SIZE + 1];
	struct termios	attr;

	r = tgetent(buf, getenv("TERM"));
	tcgetattr(STDERR_FILENO, &attr);
	attr.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
					| INLCR | IGNCR | ICRNL | IXON);
	attr.c_oflag &= ~OPOST;
	attr.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	attr.c_cflag &= ~(CSIZE | PARENB);
	attr.c_cflag |= CS8;
	tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	tputs(tgetstr("cl", NULL), 1, ft_printnbr);
	tputs(tgetstr(FULL_SCREEN, NULL), 1, ft_printnbr);
	tputs(tgetstr(HIDE_CURSOR, NULL), 1, ft_printnbr);
	return (0);
}
