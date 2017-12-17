/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 06:10:36 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 08:44:23 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

static void	shift_erase(char *line, size_t i, size_t cp)
{
	cp--;
	while (cp <= i)
	{
		line[cp] = line[cp + 1];
		cp++;
	}
}

static void	erase_back(t_line *line)
{
	tputs(tgetstr("le", NULL), 0, tputc);
	line->i--;
	line->cp--;
	line->buf[line->i] = '\0';
	tputs(tgetstr("dc", NULL), 0, tputc);
}

static void	erase_inside(t_line *line)
{
	tputs(tgetstr("le", NULL), 0, tputc);
	erase_line(line->cp - 1, line->i);
	shift_erase(line->buf, line->i, line->cp);
	write(STDOUT, SAVE_CURSOR, 3);
	write(STDOUT, line->buf + line->cp - 1, line->i - line->cp);
	tputs(tgetstr("rc", NULL), 0, tputc);
	line->cp--;
	line->i--;
}

void		erase_c(t_line *line)
{
	if (!line->cp)
		return ;
	(line->cp == line->i) ? erase_back(line) : erase_inside(line);
}

void		erase_line(size_t start, size_t end)
{
	while (start != end)
	{
		tputs(tgetstr("dc", NULL), 0, tputc);
		start++;
	}
}
