/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 13:03:47 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/11 21:13:59 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_digits(uint64_t n, int base)
{
	if (n < (uint64_t)base)
		return (1);
	else
		return (ft_count_digits(n / base, base) + 1);
}
