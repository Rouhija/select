/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 10:30:31 by srouhe           ###   ########.fr       */
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

int			column_count(int max_width)
{
	int				limit;
	int				cols;
	struct winsize	w;

	limit = 8;
	ioctl(1, TIOCGSIZE, &w);
	while (max_width >= limit)
		limit += 8;
	cols = w.ws_col / limit;
	return (cols);
}

void			print_options(char **av)
{
	int		i;
	int		j;
	int		x;
	int		cols;
	int		rows;
	int		max_w;

	max_w = 0;
	rows = 0;
	i = 0;
	j = 0;
	x = 0;
	while (av[++i])
		max_w = ft_strlen(av[i]) > max_w ? ft_strlen(av[i]) : max_w;
	cols = column_count(max_w);
	// ft_printf("columns %d max_w %d\n", cols, max_w);
	i = 0;
	while (av[++i])
	{
		ft_putstr_fd(tgoto(CM, x, rows), 0);
		ft_putendl(av[i]);
		x += max_w + 8;
		j++;
		if (j == cols - 1)
		{
			rows++;
			x = 0;
			j = 0;
			ft_putstr_fd(tgoto(CM, 0, rows), 0);
		}
	}
}

void	reset_terminal(struct termios def)
{
	tcsetattr(STDERR_FILENO, TCSANOW, &def);
	tputs(VE, 1, ft_printnbr);
	tputs(TE, 1, ft_printnbr);
}

int		main(int ac, char **av)
{
	int				r;
	char			buf[BUF_SIZE + 1];
	struct termios	attr;
	struct termios	def;

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
	print_options(av);
	// reset_terminal(def);
	return (0);
}
