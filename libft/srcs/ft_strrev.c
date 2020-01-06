/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:15:50 by srouhe            #+#    #+#             */
/*   Updated: 2019/11/11 13:17:27 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	*beg;
	char	*rev;
	char	*end;
	char	temp;

	beg = str;
	rev = str;
	end = str;
	while (*end)
		end++;
	end--;
	while (beg < end)
	{
		temp = *beg;
		*beg = *end;
		*end = temp;
		end--;
		beg++;
	}
	return (rev);
}
