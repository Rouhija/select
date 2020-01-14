/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:02:09 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/14 17:12:14 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		printnbr(int nbr)
{
	return (write(OUTPUT, &nbr, 1));
}

/*
**	Utility function for LEFT and RIGHT keypresses.
*/

void	jump_columns(long key)
{
	int		steps;

	steps = g_sel.rows + 1;
	if (key == RIGHT)
	{
		while (steps--)
		{
			g_sel.active = g_sel.active->next;
			if (g_sel.active == g_sel.head || g_sel.active == g_sel.head->prev)
				break ;
		}
	}
	else if (key == LEFT)
	{
		while (steps--)
		{
			g_sel.active = g_sel.active->prev;
			if (g_sel.active == g_sel.head || g_sel.active == g_sel.head->prev)
				break ;
		}
	}
}

char	*get_color(char *name)
{
	struct stat		attr;

	lstat(name, &attr);
	if (S_ISDIR(attr.st_mode))
		return (ft_strdup(C_DIR));
	else if (S_ISLNK(attr.st_mode))
		return (ft_strdup(C_LNK));
	else if (attr.st_mode & S_IXUSR)
		return (ft_strdup(C_EXE));
	else if (ft_endswith(name, ".h"))
		return (ft_strdup(C_HDR));
	else if (ft_endswith(name, ".o"))
		return (ft_strdup(C_OBJ));
	else if (ft_endswith(name, ".md") || ft_endswith(name, "Makefile"))
		return (ft_strdup(C_OTH));
	else
		return (ft_strdup(C_NO));
}

/*
**	Counts rows, columns and padding.
**	Return -1 if screen size is insufficient for the number of arguments.
*/

int		column_count(void)
{
	int				limit;
	struct winsize	w;

	limit = COLUMN_W;
	ioctl(OUTPUT, TIOCGSIZE, &w);
	while (g_sel.max_w >= limit)
		limit += COLUMN_W;
	g_sel.pad = limit;
	g_sel.cols = w.ws_col / limit;
	if (g_sel.cols)
		g_sel.rows = g_sel.ac > g_sel.cols ? g_sel.ac / g_sel.cols : 0;
	else
		g_sel.rows = 0;
	if (g_sel.rows + HEADER + 4 > w.ws_row || w.ws_col < 30)
	{
		ft_putstr_fd(tgoto(CM, 0, 0), 0);
		ft_putstr_fd("\e[3mPlease resize screen.\e[0m", OUTPUT);
		return (0);
	}
	return (1);
}
