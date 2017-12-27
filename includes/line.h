/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouby <agouby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 03:44:16 by agouby            #+#    #+#             */
/*   Updated: 2017/12/15 08:46:22 by agouby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "libft.h"
# include <sys/ioctl.h>

# define NB_ENTRIES	7
# define READ_LEN	6

# define IS_EOF(X)	(X == 4)
# define IS_PRINT(X)	(X > 31 && X < 127)
# define IS_ENTER(X)	(X == 10)
# define IS_DEL_F(X)	(X == 127)
# define IS_DEL_B(X)	(X == 268)
# define IS_ARROW(X)	(X > 182 && X < 187)

# define IS_UP(X)	(X == 183)
# define IS_DOWN(X)	(X == 184)
# define IS_RIGHT(X)	(X == 185)
# define IS_LEFT(X)	(X == 186)

# define INIT_LINE_SIZE	168

typedef	struct	s_line
{
	char	*buf;
	size_t	i;
	size_t	len;
	size_t	cp;
	struct winsize w;
}		t_line;

typedef struct	s_key
{
	char	buf[READ_LEN];
	int	val;
	int	ret;
	int	id;
}		t_key;

void		init_line(t_line *line);
void		reset_line(t_line *line);
void		resize_line_buf(t_line *line);

int		read_input(t_key *key);

int		combine_key_val(const char *buf, int *val);
int		get_key_index(int val);

void		enter_pressed(int val);
void		printable_pressed(int val);
void		del_f_pressed(int val);

void		arrow_pressed(int val);
void		left_pressed(void);
void		right_pressed(void);
void		up_pressed(void);
void		down_pressed(void);

void		*line_sgt(void *line);
void		*arrow_sgt(int b);

void		resize(int sig);

void		insert_back(t_line *line, int val);
void		insert_inside(t_line *line, int val);

void		delete_inside();

#endif
