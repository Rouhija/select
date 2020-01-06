/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:15:52 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 19:34:04 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** -------- HEADERS --------
*/

# include "libft.h"
# include <termcap.h>
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

# define BUF_SIZE 2048

/*
** -------- FUNCTIONS --------
*/

#endif
