/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:25:50 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 03:57:49 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	resize_line(t_line *line)
{
	char	*temp;

	if (!(temp = ft_strdup(line->buf)))
		ft_memerr();
	ft_strdel(&line->buf);
	line->size *= 2;
	if (!(line->buf = (char *)ft_memalloc(line->size)))
		ft_memerr();
	ft_strcpy(line->buf, temp);
	ft_strdel(&temp);
}

void		reset_line(t_line *line)
{
	if (line->size == INIT_LINE_SIZE)
	{
		ft_bzero(line->buf, line->i);
		line->i = 0;
	}
	else
	{
		line->i = 0;
		line->size = INIT_LINE_SIZE;
		ft_strdel(&line->buf);
		if (!(line->buf = ft_memalloc(INIT_LINE_SIZE)))
			ft_memerr();
	}
}

int			init_line(t_line *line)
{
	if (INIT_LINE_SIZE <= 0)
		return (-1);
	line->i = 0;
	line->size = INIT_LINE_SIZE;
	if (!(line->buf = ft_memalloc(INIT_LINE_SIZE)))
		ft_memerr();
	return (NO_ERR);
}

void		putc_line(t_line *line, char c)
{
	if (line->i == line->size)
		resize_line(line);
	line->buf[line->i++] = c;
	write(STDOUT, &c, 1);
}
