/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:44:16 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 08:46:22 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include "libft.h"

# define IS_EOF(X)		(X == 4)
# define IS_ENTER(X)	(X == 10)
# define IS_PRINT(X)	(X > 31 && X < 127)
# define IS_DEL_F(X)	(X == 127)
# define IS_DEL_B(X)	(X == 268)
# define IS_KEY(X)		(X > 182 && X < 187)

# define IS_UP(X)		(X == 183)
# define IS_DOWN(X)		(X == 184)
# define IS_RIGHT(X)	(X == 185)
# define IS_LEFT(X)		(X == 186)

# define SMALLEST_ARROW 185

# define INIT_LINE_SIZE	128
# define SAVE_CURSOR	"\033[s"

typedef	struct	s_line
{
	char	*buf;
	size_t	i;
	size_t	size;
	size_t	cp;
	void	(*cm_func[2])(struct s_line *line);
}				t_line;

typedef struct	s_key
{
	char	buf[3];
	int		n;
}				t_key;

int		init_line(t_line *line);
void	putc_line(t_line *line, char c);
void	erase_c(t_line *line);
void	reset_line(t_line *line);
void	shift_insert(char *line, size_t i ,size_t cp, char c);
void	erase_line(size_t start, size_t end);

void	insert_back(t_line *line, char c);
void	insert_inside(t_line *line, char c);

void	move_cursor(t_line *line, int arrow);
void	move_left(t_line *line);
void	move_right(t_line *line);

int		get_key(char *buf);

#endif
