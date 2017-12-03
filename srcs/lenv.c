/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:44:37 by agouby            #+#    #+#             */
/*   Updated: 2017/12/03 14:56:17 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tenv.h"
#include "ft_printf.h"

t_lenv	*lenv_new(char *key, char *value)
{
	t_lenv	*new;

	if (!(new = (t_lenv *)malloc(sizeof(t_lenv))))
		ft_memerr();
	new->key = key;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	lenv_add(t_lenv **old, t_lenv *new)
{
	new->next = *old;
	*old = new;
}

void	lenv_addb(t_lenv **old, t_lenv *new)
{
	t_lenv	*tmp;

	if (!*old)
	{
		*old = new;
		return ;
	}
	tmp = *old;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	lenv_print(t_lenv *lenv)
{
	while (lenv)
	{
		ft_printf("%s=%s\n", lenv->key, lenv->value);
		lenv = lenv->next;
	}
}
