/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:44:16 by agouby            #+#    #+#             */
/*   Updated: 2017/12/14 04:04:48 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# define IS_EOF(X)		(X == 4)
# define IS_ENTER(X)	(X == 10)
# define IS_PRINT(X)	(X > 31 && X < 127)
# define IS_DEL(X)		(X == 127)
# define IS_KEY(X)		(x == 27)

# define INIT_LINE_SIZE	128

typedef	struct	s_line
{
	char	*buf;
	size_t	i;
	size_t	size;
}				t_line;

int		init_line(t_line *line);
void	putc_line(t_line *line, char c);
void	reset_line(t_line *line);

#endif
