/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 12:02:09 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/08 13:52:08 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		printnbr(int nbr)
{
	return (write(2, &nbr, 1));
}

int		step_count(long key)
{
	int steps;

	steps = g_sel.rows + 1;
	if (g_sel.active->coord.x == g_sel.cols && key == RIGHT)
		steps -= g_sel.lacking;
	else if (g_sel.active->coord.x == 1 && key == LEFT && g_sel.active->coord.y + g_sel.lacking > g_sel.rows + 1)
		steps += g_sel.rows + 1 - g_sel.lacking;
	else if (g_sel.active->coord.x == g_sel.cols - 1 && key == RIGHT && g_sel.active->coord.y + g_sel.lacking > g_sel.rows + 1)
		steps += g_sel.rows + 1 - g_sel.lacking;
	else if (g_sel.active->coord.x == 1 && key == LEFT)
		steps -= g_sel.lacking;
	return (steps);
}

char	*get_color(char *name)
{
	if (ft_strstr(name, "Makefile"))
		return (ft_strdup(C_MAKEFILE));
	else if (ft_strstr(name, ".o"))
		return (ft_strdup(C_OBJ));
	else if (ft_strstr(name, ".a"))
		return (ft_strdup(C_A));
	else
		return (ft_strdup(C_NO));
}

void	column_count(void)
{
	int				limit;
	int				cols;
	struct winsize	w;

	limit = COLUMN_W;
	ioctl(1, TIOCGSIZE, &w);
	while (g_sel.max_w >= limit)
		limit += COLUMN_W;
	g_sel.pad = limit;
	g_sel.cols = w.ws_col / limit;
	g_sel.rows = g_sel.ac > g_sel.cols ? g_sel.ac / g_sel.cols : 0;
	g_sel.lacking = (g_sel.cols * (g_sel.rows + 1)) % g_sel.ac;
}

void	cursor_move(int x, int y)
{
	ft_putstr_fd(tgoto(CM, x, y + HEADER), 0);
	g_sel.x = x;
	g_sel.y = y;
	g_sel.args->coord.x = x / g_sel.pad + 1;
	g_sel.args->coord.y = y + 1;
}
