/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:25:50 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 07:59:12 by agouby           ###   ########.fr       */
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
	line->cp = 0;
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
	line->cp = 0;
	line->size = INIT_LINE_SIZE;
	line->cm_func[0] = move_right;
	line->cm_func[1] = move_left;
	if (!(line->buf = ft_memalloc(INIT_LINE_SIZE)))
		ft_memerr();
	return (NO_ERR);
}

void		putc_line(t_line *line, char c)
{
	if (line->i == line->size)
			resize_line(line);
	(line->i != line->cp) ? insert_inside(line, c) : insert_back(line, c);
}
