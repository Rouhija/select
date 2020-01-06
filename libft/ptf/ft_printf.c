/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhe <srouhe@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 12:58:13 by srouhe            #+#    #+#             */
/*   Updated: 2020/01/04 18:00:56 by srouhe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_ptf		*initialize(char *format)
{
	t_ptf		*p;

	if (!(p = ft_memalloc(sizeof(t_ptf))))
		return (NULL);
	p->fmt = format;
	p->fptr = format;
	p->buf_index = 0;
	p->index = 0;
	p->len = 0;
	p->width = 0;
	p->flags = 0;
	return (p);
}

/*
** Buffer management functions replicating real printf.
** Fill the buffer with dynamically allocated tmp string. If full, flush it.
** Clear and free tmp string and reset struct values.
*/

void				flush_buffer(t_ptf **p)
{
	write(1, (*p)->buf, (*p)->buf_index);
	ft_bzero((*p)->buf, BUF_SIZE);
	(*p)->buf_index = 0;
}

void				fill_buffer(t_ptf **p)
{
	int	i;

	i = 0;
	if (!(*p)->tmp)
		return ;
	while ((*p)->tmp[i])
	{
		(*p)->buf[(*p)->buf_index++] = (*p)->tmp[i++];
		(*p)->len++;
		if ((*p)->buf_index == BUF_SIZE || (*p)->buf[(*p)->buf_index] == '\n')
			flush_buffer(p);
	}
	if ((*p)->tmp)
	{
		free((*p)->tmp);
		(*p)->tmp = NULL;
	}
	(*p)->width = 0;
	(*p)->flags = 0;
	(*p)->prec = 0;
	(*p)->tmplen = 0;
	(*p)->padc = ' ';
}

/*
** Flush buffer, free mem and exit ptf with return length.
*/

u_int64_t			exit_pft(t_ptf **p)
{
	u_int64_t r;

	r = (*p)->len;
	flush_buffer(p);
	free(*p);
	p = NULL;
	return (r);
}

int					ft_printf(const char *restrict format, ...)
{
	t_ptf		*p;

	if (!(p = initialize((char *)format)))
		return (-1);
	va_start(p->ap, format);
	while ((p->index = ft_lfind(p->fptr, '%')) != -1)
	{
		p->tmp = ft_memdup(p->fptr, p->index);
		fill_buffer(&p);
		p->fptr += p->index + 1;
		parse_format(&p);
		p->c ? format_argumet(&p) : PASS;
	}
	p->tmp = ft_memdup(p->fptr, ft_strlen(p->fptr));
	fill_buffer(&p);
	va_end(p->ap);
	return (exit_pft(&p));
}
