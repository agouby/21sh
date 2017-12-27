/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:36:44 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 07:50:06 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		routine(t_env *e)
{
	t_line	line;
	t_key	key;
	void	(*process_input[NB_ENTRIES])(int val);

	init_process_input(process_input);
	init_line(&line);
	ft_bzero(&key, sizeof(t_key));
	arrow_sgt(1);
	while (1)
	{
		reset_line(&line);
		print_prompt();
		key.val = 0;
		while (!IS_EOF(key.val) && !IS_ENTER(key.val))
		{
			if (read_input(&key) == -1)
				return (-1);
			key.id = get_key_index(key.val);
			if (key.id != -1)
				process_input[key.id](key.val);
			line_sgt(&line);
		}
		if (IS_EOF(key.val))
			break ;
	}
	return (NO_ERR);
}
