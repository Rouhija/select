/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:47:10 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 18:29:12 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**		Join two strings into a valid path
*/

char			*ft_pathjoin(char *s1, char *s2)
{
	char	*path;
	char	*tmp;

	if (s1[ft_strlen(s1) - 1] == '/' && s2[0] == '/')
		path = ft_strjoin(s1, s2 + 1);
	else if (s1[ft_strlen(s1) - 1] == '/' || s2[0] == '/')
		path = ft_strjoin(s1, s2);
	else
	{
		tmp = ft_strjoin(s1, "/");
		path = ft_strjoin(tmp, s2);
		free(tmp);
	}
	return (path);
}
