/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 06:10:36 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 02:30:25 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

void	delete_c(t_line *line)
{
	if (!line->i)
		return ;
	tputs(tgetstr("le", NULL), 0, putc);
	line->i--;
	line->buf[line->i] = '\0';
	tputs(tgetstr("dc", NULL), 0, putc);
}
