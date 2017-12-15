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
	int		ret;

	if (init_line(&line) == -1)
		return (e->err = ERR_INIT_LINE);
	while (1)
	{
		print_prompt();
		key.n = 0;
		while (!IS_EOF(key.n) && !IS_ENTER(key.n))
		{
			ret = read(STDIN, key.buf, 3);
			key.buf[ret] = '\0';
			key.n = get_key(key.buf);
			if (IS_PRINT(key.n))
				putc_line(&line, *key.buf);
			else if (IS_ENTER(key.n))
			{
				write(STDOUT, "\n", 1);
				ft_printf("        {%s}\n", line.buf);
				reset_line(&line);
			}
			else if (IS_DEL_F(key.n))
				erase_c(&line);
			else if (IS_KEY(key.n))
			{
				move_cursor(&line, key.n);
			}
//			ft_printf("KEY PRESSED: {%d}\n", key.n);
		}
		if (IS_EOF(key.n))
			break;
	}
	return (NO_ERR);
}
