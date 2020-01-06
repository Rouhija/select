/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:54:45 by srouhe            #+#    #+#             */
/*   Updated: 2019/11/10 18:18:19 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_print_bits(uint64_t bits, int len)
{
	uint64_t		bit;

	while (len--)
	{
		bit = (bits >> len & 1) + '0';
		write(1, &bit, 1);
		if (len % 8 == 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
