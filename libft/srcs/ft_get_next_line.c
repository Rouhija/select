/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:32:52 by srouhe            #+#    #+#             */
/*   Updated: 2019/11/04 11:25:18 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	yield_line(int fd, int n_read, char **line, char **s)
{
	char		*tmp;

	if (n_read < 0)
		return (-1);
	else if (n_read == 0 && s[fd] == NULL)
		return (0);
	else if (ft_strchr(s[fd], '\n'))
	{
		*line = ft_strsub(s[fd], 0, ft_strchr(s[fd], '\n') - s[fd]);
		tmp = ft_strdup(s[fd] + ft_strlen(*line) + 1);
		free(s[fd]);
		s[fd] = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
		if (!ft_strlen(*line))
			return (0);
		return (1);
	}
}

int			ft_get_next_line(const int fd, char **line)
{
	static char	*s[1024];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			n_read;

	if (fd < 0 || !line)
		return (-1);
	while ((n_read = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[n_read] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		tmp = ft_strjoin(s[fd], buf);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (yield_line(fd, n_read, line, s));
}
