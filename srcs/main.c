/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 03:26:17 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 01:29:20 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		main(void)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	get_tenv(&e.lenv);
	configure_terminal(&e);
	init_signals();
	routine(&e);
	restore_terminal(&e);
	return (EXIT_SUCCESS);
}
