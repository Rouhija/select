/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:35:12 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 16:26:46 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_splits(char const *str, char c)
{
	int	i;
	int flag;
	int words;

	i = 0;
	flag = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && !flag)
		{
			words++;
			flag = 1;
		}
		else if (str[i] == c)
			flag = 0;
		i++;
	}
	return (words);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		flag;

	if (!s || !(arr = (char **)malloc(sizeof(char *) * (ft_splits(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && !flag)
		{
			flag = 1;
			arr[j] = ft_memalloc(ft_len(&s[i], c) + 1);
			ft_strncpy(arr[j], &s[i], ft_len(&s[i], c));
			j++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	arr[j] = 0;
	return (arr);
}
