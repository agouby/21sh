/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 02:17:54 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 07:51:09 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	move_left(t_line *line)
{
	if (!line->cp)
		return ;
	tputs(tgetstr("le", NULL), 0, tputc);
	line->cp--;
}

void	move_right(t_line *line)
{
	if (line->cp == line->i)
		return ;
	tputs(tgetstr("nd", NULL), 0, tputc);
	line->cp++;
}

void	move_cursor(t_line *line, int arrow)
{
	(void)line;
	if (IS_LEFT(arrow) || IS_RIGHT(arrow))
		line->cm_func[arrow - SMALLEST_ARROW](line);
}
