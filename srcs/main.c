/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 19:10:26 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/06 19:34:57 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int ac, char **av)
{
	int		r;
	char	*term;
	char	buf[BUF_SIZE + 1];

	term = getenv("TERM");
	r = tgetent(buf, term);
	return (0);
}
