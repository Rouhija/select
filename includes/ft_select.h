/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:15:52 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/07 09:47:32 by srouhe           ###   ########.fr       */
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
# include <dirent.h>
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

# define CM (tgetstr("cm", NULL))
# define CL (tgetstr("cl", NULL))
# define VI (tgetstr("vi", NULL))
# define TI (tgetstr("ti", NULL))

typedef struct		s_sel
{
	struct termios	attr;
}					t_sel;

/*
** -------- FUNCTIONS --------
*/

#endif
