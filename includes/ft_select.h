/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:15:52 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/13 20:34:07 by srouhe           ###   ########.fr       */
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
** -------- TYPEDEFS --------
*/

# ifndef TIOCGSIZE
#  define TIOCGSIZE TIOCGWINSZ
# endif

# define BUF_SIZE 4096
# define COLUMN_W 8
# define HEADER 4
# define OUTPUT 2
# define M_EOF "\x1A"

# define INVERSE_VIDEO "\033[7m"
# define UNDERLINE "\033[4m"
# define C_OBJ "\033[01;30m"
# define C_DIR "\033[01;32m"
# define C_OTH "\033[22;34m"
# define C_EXE "\033[22;31m"
# define C_LNK "\033[22;36m"
# define C_HDR "\033[22;35m"
# define C_NO "\033[22;37m"
# define HEADING "\033[01;34m"

# define EXIT_0 "ft_select: graceful exit."
# define EXIT_1 "usage: ./ft_select arg1 [arg2] ..."
# define EXIT_2 "ft_select: terminal configuration not found."
# define EXIT_3 "ft_select: malloc error."
# define EXIT_4 "ft_select: incorrect environment."
# define EXIT_5 "ft_select: termcaps database not found."
# define EXIT_6 "ft_select: terminal not found in termcaps database."
# define EXIT_7 "ft_select: TERM environment value not found."

# define ESC 0x1B
# define SPC 0x20
# define ENT 0xA
# define BKS 0x7F
# define DEL 0x7E335B1B
# define A_UP 0x41
# define A_LO 0x5A
# define UP 0x415B1B
# define DOWN 0x425B1B
# define RIGHT 0x435B1B
# define LEFT 0x445B1B

/*
** Definitions of termcaps tuples:
**  CM: cursor motion
**  CL: clear screen
**  CE: clear line
**  VI: invisible cursor
**  VE: visible cursor
**  TI: full screen
**  TE: return to normal mode
*/

# define CM (tgetstr("cm", NULL))
# define CL (tgetstr("cl", NULL))
# define CE (tgetstr("ce", NULL))
# define VI (tgetstr("vi", NULL))
# define VE (tgetstr("ve", NULL))
# define TI (tgetstr("ti", NULL))
# define TE (tgetstr("te", NULL))

typedef struct		s_arg
{
	int				toggle;
	char			*name;
	char			*path;
	char			*color;
	struct s_arg	*next;
	struct s_arg	*prev;
}					t_arg;

typedef struct		s_sel
{
	struct termios	attr;
	struct termios	def;
	t_arg			*args;
	t_arg			*head;
	t_arg			*active;
	int				ac;
	int				selected;
	int				max_w;
	int				pad;
	int				x;
	int				y;
	int				cols;
	int				rows;
}					t_sel;

t_sel				g_sel;

/*
** -------- FUNCTIONS --------
*/

int					printnbr(int nbr);
int					column_count(void);
char				*get_color(char *name);
void				initial_config(void);
void				reset_config(void);
void				exit_program(int code, int flag);
void				monitor_signals(void);
void				signal_handler(int signo);
void				wait_for_input(void);
void				set_args(char **av);
void				free_arg(t_arg **arg);
void				free_memory(void);
void				print_args(void);
void				print_selection(void);
void				jump_columns(long key);
void				cursor_move(int x, int y);
void				action_bks(void);
void				action_spc(void);
void				action_arrow(long key);
void				action_all(long key);

#endif
