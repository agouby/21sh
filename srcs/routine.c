/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:36:44 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 04:04:42 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		routine(t_env *e)
{
	char	r_buf[3];
	t_line	line;

	(void)e;
	if (init_line(&line) == -1)
		return (e->err = ERR_INIT_LINE);
	while (1)
	{
		print_prompt();
		ft_bzero(r_buf, 3);
		while (!IS_EOF(*r_buf) && !IS_ENTER(*r_buf))
		{
			read(STDIN, r_buf, 3);
			if (IS_PRINT(*r_buf))
				putc_line(&line, *r_buf);
			else if (IS_ENTER(*r_buf))
			{
				write(STDOUT, "\n", 1);
				reset_line(&line);
			}
			else if (IS_DEL(*r_buf))
				delete_c(&line);
/*			else if (IS_KEY(*r_buf))
			{
				move_cursor();
			}
*/			ft_printf("KEY PRESSED: {%d}, {%d}, {%d}\n",
					(int)*r_buf, (int)*(r_buf + 1), (int)*(r_buf + 2));
		}
		if (IS_EOF(*r_buf))
			break;
	}
	return (NO_ERR);
}
