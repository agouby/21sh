/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:02:11 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 00:54:05 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		get_key_and_value(char *line, char **key, char **value)
{
	size_t	cut;

	if ((cut = (ft_strchr(line, '=') - line)) < 1)
		return (-1);
	if (!(*key = (char *)malloc(cut + 1)))
		ft_memerr();
	ft_strncpy(*key, line, cut);
	if (!(*value = ft_strdup(line + cut + 1)))
		ft_memerr();
	return (NO_ERR);
}

char	*fetch_lenv_value(t_lenv *lenv, char *key)
{
	while (lenv)
	{
		if (ft_strequ(lenv->key, key))
			return (lenv->value);
		lenv = lenv->next;
	}
	return (NULL);
}

void	get_tenv(t_lenv **lenv)
{
	extern char		**environ;
	char			*key;
	char			*value;

	while (*environ)
	{
		if (get_key_and_value(*environ, &key, &value) != -1)
			lenv_addb(lenv, lenv_new(key, value));
		environ++;
	}
}
