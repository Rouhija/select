/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 15:31:18 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/19 12:07:44 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** finds the first instance of c from the left.
*/

int		ft_lfind(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
