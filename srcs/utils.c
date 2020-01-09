/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:02:09 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/09 16:11:14 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		step_count(long key)
{
	int steps;

	steps = g_sel.rows + 1;
	if (g_sel.active->coord.x == g_sel.cols && key == RIGHT)
		steps -= g_sel.lacking - JUMP;
	else if (g_sel.active->coord.x == g_sel.cols - 1 && key == RIGHT &&
			g_sel.active->coord.y + g_sel.lacking > g_sel.rows + 1)
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
	else
		return (ft_strdup(C_NO));
}

void	column_count(void)
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
	g_sel.lacking = (g_sel.cols * (g_sel.rows + 1)) % g_sel.ac;
}
