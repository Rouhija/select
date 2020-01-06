/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:40:31 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/17 11:30:30 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	long	wall;

	wall = nb;
	if (wall < 0)
	{
		ft_putchar('-');
		wall *= -1;
	}
	if (wall < 10)
	{
		ft_putchar(wall + '0');
	}
	else
	{
		ft_putnbr(wall / 10);
		ft_putnbr(wall % 10);
	}
}
