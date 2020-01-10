/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:02:09 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/10 21:18:48 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

/*
**	Horrible function to calculate the steps for moving in linked list.
**	Logic for LEFT and RIGHT keys in case cursor is on the edge of the area.
*/

int		step_count(long key)
{
	int steps;

	steps = g_sel.rows + 1;
	if (g_sel.active->coord.x == g_sel.cols && key == RIGHT)
		steps -= g_sel.lacking - JUMP;
	else if (g_sel.active->coord.x == g_sel.cols - 1 && key == RIGHT &&
			g_sel.active->coord.y + g_sel.lacking > g_sel.rows + 1)
		steps += g_sel.rows + 1 - g_sel.lacking + JUMP;
	else if (g_sel.active->prev->coord.x == 1 && key == LEFT &&
			g_sel.active->prev->coord.y + g_sel.lacking > g_sel.rows + 2)
		steps += g_sel.rows + 1 - g_sel.lacking + JUMP;
	else if (g_sel.active->coord.x == 1 && key == LEFT &&
			g_sel.active->coord.y + g_sel.lacking > g_sel.rows + 2)
		steps += g_sel.rows + 1 - g_sel.lacking + JUMP;
	else if (g_sel.active->coord.x == 1 && key == LEFT)
		steps -= g_sel.lacking - JUMP;
	return (steps);
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
**	Is screen is of insufficient size, waits resizing for 30 seconds.
*/

int		column_count(void)
{
	int				limit;
	int				cols;
	struct winsize	w;

	limit = COLUMN_W;
	ioctl(OUTPUT, TIOCGSIZE, &w);
	while (g_sel.max_w >= limit)
		limit += COLUMN_W;
	g_sel.pad = limit;
	g_sel.cols = w.ws_col / limit;
	g_sel.rows = g_sel.ac > g_sel.cols ? g_sel.ac / g_sel.cols : 0;
	if (g_sel.rows + HEADER + 2 > w.ws_row)
	{
		ft_putstr_fd(tgoto(CM, 0, 0), 0);
		ft_putstr_fd("\e[3mPlease resize screen.\e[0m", OUTPUT);
		return (0);
	}
	g_sel.lacking = (g_sel.cols * (g_sel.rows + 1)) % g_sel.ac;
	return (1);
}
