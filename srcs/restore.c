/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:43:55 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 00:54:28 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		restore_terminal(t_env *e)
{
	e->tmios.c_lflag &= (ECHO | ICANON);
	if (tcsetattr(STDIN, TCSANOW, &e->tmios) == -1)
		return (e->err = ERR_SETATTR);
	return (NO_ERR);
}
