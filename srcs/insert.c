/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 05:15:18 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 08:46:58 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	insert_back(t_line *line, char c)
{
	line->buf[line->i++] = c;
	line->cp++;
	write(STDOUT, &c, 1);
}

void	insert_inside(t_line *line, char c)
{
	erase_line(line->cp, line->i);
	shift_insert(line->buf, line->i, line->cp, c);
	write(STDOUT, SAVE_CURSOR, 3);
	write(STDOUT, line->buf + line->cp, line->i - line->cp + 1);
	tputs(tgetstr("rc", NULL), 0, putc);
	tputs(tgetstr("nd", NULL), 0, putc);		
	line->cp++;
	line->i++;
}