/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 23:29:13 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 02:08:13 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include "ft_printf.h"
# include "tenv.h"
# include "errors.h"
# include "read.h"
# include <term.h>
# include <termios.h>

# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define PROMPT		"\e[92magouby\e[91m $ \e[39m"
# define PROMPT_LEN	24

typedef struct	s_env
{
	int				err;
	t_lenv			*lenv;
	struct termios	tmios;
}				t_env;

int				configure_terminal(t_env *e);
int				restore_terminal(t_env *e);
int				routine(t_env *e);
int				putc(int c);
void			delete_c(t_line *line);
void			print_prompt(void);

#endif
