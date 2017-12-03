/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tenv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:03:38 by agouby            #+#    #+#             */
/*   Updated: 2017/12/03 15:14:24 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TENV_H
# define TENV_H

typedef struct	s_lenv
{
	char			*key;
	char			*value;
	struct s_lenv	*next;
}				t_lenv;

void			get_tenv(t_lenv **lenv);
char			*fetch_lenv_value(t_lenv *lenv, char *key);

t_lenv			*lenv_new(char *key, char *value);
void			lenv_add(t_lenv **old, t_lenv *n);
void			lenv_addb(t_lenv **old, t_lenv *n);
void			lenv_print(t_lenv *lenv);

#endif
