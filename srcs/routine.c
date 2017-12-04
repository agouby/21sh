/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:36:44 by agouby            #+#    #+#             */
/*   Updated: 2017/12/04 06:10:32 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		routine(t_env *e)
{
	char	r_buf[3];
	t_line	line;

	(void)e;
	init_line(&line);
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
				write(STDOUT, "\n", 1);
			else if (IS_DEL(*r_buf))
				delete_c(&line);
//			ft_printf("KEY PRESSED: {%d}, {%d}, {%d}\n",
//					(int)*r_buf, (int)*(r_buf + 1), (int)*(r_buf + 2));
		}
		if (IS_EOF(*r_buf))
			break;
	}
	return (0);
}
