/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:29:13 by agouby            #+#    #+#             */
/*   Updated: 2017/12/03 16:17:39 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_SH_H
# define FT_SH_H

# include "ft_printf.h"
# include "tenv.h"
# include "errors.h"
# include <term.h>
# include <termios.h>

# define STDIN		0
# define STDOUT		1
# define STDERR		2

typedef struct	s_env
{
	int				err;
	t_lenv			*lenv;
	struct termios	tmios;
}				t_env;

int		configure_terminal(t_env *e);
int		restore_terminal(t_env *e);

#endif
