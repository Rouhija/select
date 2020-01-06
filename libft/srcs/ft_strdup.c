/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 18:48:46 by srouhe            #+#    #+#             */
/*   Updated: 2019/12/13 15:06:06 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;

	if (!(cpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	return (ft_strcpy(cpy, (char *)src));
}
