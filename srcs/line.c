/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:25:50 by agouby            #+#    #+#             */
/*   Updated: 2017/12/04 04:29:59 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	init_line(t_line *line)
{
	line->init_size = INIT_LINE_SIZE;
	line->i = 0;
	if (!(line->buf = (char *)ft_memalloc(line->init_size)))
		ft_memerr();
}

void	putc_line(t_line *line, char c)
{
	line->buf[line->i] = c;
	line->i++;
	write(STDOUT, &c, 1);
}
