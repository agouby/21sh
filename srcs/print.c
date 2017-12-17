/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:15:30 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 03:07:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh.h"

int		tputc(int c)
{
	return (write(STDOUT, &c, 1));
}

void	print_prompt(void)
{
	write(STDOUT, PROMPT, PROMPT_LEN);
}
