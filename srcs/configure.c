/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 12:45:05 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 00:54:16 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		configure_terminal(t_env *e)
{
	char	*term;

	if (!(term = fetch_lenv_value(e->lenv, "TERM")))
		return (e->err = ERR_TERM_VAR);
	if (tgetent(NULL, term) == -1)
		return (e->err = ERR_ENTRY);
	if (tcgetattr(STDIN, &e->tmios) == -1)
		return (e->err = ERR_GETATTR);
	e->tmios.c_lflag &= ~(ICANON);
	e->tmios.c_lflag &= ~(ECHO);
	if (tcsetattr(STDIN, TCSANOW, &e->tmios) == -1)
		return (e->err = ERR_SETATTR);
	return (NO_ERR);
}
