/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 09:44:29 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

void		errors(char *arg, int code)
{
	code == 2 ? ft_printf("ft_select: failed to open %s\n", arg) : PASS;
}

void			column_count(int width)
{
	int				limit;
	int				cols;
	struct winsize	w;

	limit = 8;
	ioctl(1, TIOCGSIZE, &w);
	while (width >= limit)
		limit += 8;
	cols = w.ws_col / limit;
}

void			read_dir(char *dirname)
{
	int						x;
	struct dirent			*dp;
	DIR						*dir;

	x = 8;
	!(dir = opendir(dirname)) ? errors(dirname, 2) : PASS;
	if (dir)
	{
		while ((dp = readdir(dir)))
		{
			ft_putstr_fd(tgoto(CM, x, 0), 0);
			ft_putendl((*dp).d_name);
			x += ft_strlen((*dp).d_name) + 8;
		}
	}
	dir ? closedir(dir) : PASS;
}

int		main(int ac, char **av)
{
	int				r;
	char			buf[BUF_SIZE + 1];
	struct termios	attr;

	r = tgetent(buf, getenv("TERM"));
	tcgetattr(STDERR_FILENO, &attr);
	// attr.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
					// | INLCR | IGNCR | ICRNL | IXON);
	attr.c_oflag &= ~OPOST;
	attr.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
	// attr.c_cflag &= ~(CSIZE | PARENB);
	// attr.c_cflag |= CS8;
	tcsetattr(STDERR_FILENO, TCSANOW, &attr);
	tputs(CL, 1, ft_printnbr);
	tputs(TI, 1, ft_printnbr);
	tputs(VI, 1, ft_printnbr);
	read_dir(av[1]);
	return (0);
}
