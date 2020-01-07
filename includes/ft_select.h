/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:15:52 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 12:57:24 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** -------- HEADERS --------
*/

# include "libft.h"
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <sys/stat.h>

/*
** -------- MACROS --------
*/

/*
** -------- TYPEDEFS --------
*/

# ifndef TIOCGSIZE
#  define TIOCGSIZE TIOCGWINSZ
# endif

# define BUF_SIZE 4096

# define ESC 0x1B
# define SPC 0x20
# define ENT 0xA
# define BKS 0x7F
# define DEL 0x7E335B1B
# define UP 0x415B1B
# define DOWN 0x425B1B
# define RIGHT 0x435B1B
# define LEFT 0x445B1B

/*
** Definitions of termcaps tuples:
**  CM: cursor motion
**  CL: clear screen
**  VI: invisible cursor
**  VE: visible cursor
**  TI: full screen
**  TE: return to normal mode
*/

# define CM (tgetstr("cm", NULL))
# define CL (tgetstr("cl", NULL))
# define VI (tgetstr("vi", NULL))
# define VE (tgetstr("ve", NULL))
# define TI (tgetstr("ti", NULL))
# define TE (tgetstr("te", NULL))

typedef struct		s_arg
{
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct		s_sel
{
	struct termios	attr;
	struct termios	def;
	t_arg			*args;
	char			**av;
	int				max_w;
	int				mode;
}					t_sel;

t_sel				g_sel;

/*
** -------- FUNCTIONS --------
*/

int		printnbr(int nbr);

void	initial_config(void);
void	reset_config(void);
void	exit_program(char *arg, int code, int flag);
void	signal_handler(int signo);
void	wait_for_input(void);
void	print_args(void);

#endif
