/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:46:40 by srouhe            #+#    #+#             */
/*   Updated: 2019/10/18 13:48:28 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	wall;

	wall = nb;
	if (wall < 0)
	{
		ft_putchar_fd('-', fd);
		wall *= -1;
	}
	if (wall < 10)
	{
		ft_putchar_fd(wall + '0', fd);
	}
	else
	{
		ft_putnbr_fd(wall / 10, fd);
		ft_putnbr_fd(wall % 10, fd);
	}
}
