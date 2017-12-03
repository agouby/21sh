/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:02:11 by agouby            #+#    #+#             */
/*   Updated: 2017/12/03 16:17:35 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		get_key_and_value(char *line, char **key, char **value)
{
	size_t	cut;

	if ((cut = ft_strchr(line, '=') - line) < 1)
		return (-1);
	*key = ft_strndup(line, cut);
	*value = ft_strdup(line + cut + 1);
	return (0);
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
	lenv_print(*lenv);
}
