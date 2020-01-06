/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 13:42:22 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 18:22:20 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -------- HEADERS --------
*/

# include <stdarg.h>
# include "libft.h"

/*
** -------- MACROS --------
*/

# define BUF_SIZE 255
# define FLAGS "#0- +"
# define CONVERSION "cspdiouxXfeEgGbzj%"

# define F_HASH		(1 << 0)
# define F_ZERO		(1 << 1)
# define F_MINUS	(1 << 2)
# define F_SPACE	(1 << 3)
# define F_PLUS		(1 << 4)
# define PREC		(1 << 5)
# define L_HH		(1 << 6)
# define L_H		(1 << 7)
# define L_L		(1 << 8)
# define L_LL		(1 << 9)
# define L_J		(1 << 10)
# define L_Z		(1 << 11)

# define HEX_PRE	(1 << 12)
# define PRECNBR	(1 << 13)
# define PRECSTR	(1 << 14)
# define PADLEAD	(1 << 15)
# define PADTRAIL	(1 << 16)
# define NUL		(1 << 17)

/*
** -------- TYPEDEFS --------
*/

typedef struct	s_ptf
{
	int			buf_index;
	int			width;
	int			flags;
	int			prec;
	int64_t		index;
	u_int64_t	len;
	u_int64_t	tmplen;
	char		*fmt;
	char		*tmp;
	char		buf[BUF_SIZE];
	char		*fptr;
	char		*args;
	char		c;
	char		padc;
	va_list		ap;
}				t_ptf;

typedef void	(*t_s_mod)(t_ptf **);

typedef struct	s_mod
{
	int			index;
	t_s_mod		func;
}				t_mod;

/*
** -------- FUNCTIONS --------
*/

void			parse_arg(t_ptf **p);
void			parse_format(t_ptf **p);
void			parse_colors(t_ptf **p);
void			format_argumet(t_ptf **p);
void			fill_buffer(t_ptf **p);
void			prec_nbr(t_ptf **p);
void			prec_str(t_ptf **p);
void			padding_leading(t_ptf **p);
void			padding_trailing(t_ptf **p);
void			hex_prefix(t_ptf **p);

char			*pop_signed(t_ptf **p);
char			*pop_unsigned(t_ptf **p);
char			*pop_string(t_ptf **p);
char			*pop_char(t_ptf **p);

#endif
