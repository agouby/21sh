#include "ft_sh.h"

static void	skip_left(t_line line, size_t *curs, int (*func)(int c))
{
	while (CURS_POS(*curs) && func(line.buf[CURS_POS(*curs) - 1]))
	{
		if (!(line.cp % line.w.ws_col - 1))
		{
			tputs(tgoto(tgetstr("ch", NULL), 0, line.w.ws_col), 0, tputc);
			tputs(tgetstr("up", NULL), 0, tputc);
		}
		else
			tputs(tgetstr("le", NULL), 0, tputc);
		--line.cp;
		--(*curs);
	}
}

static void	skip_right(t_line line, size_t *curs, int (*func)(int c))
{
	while (line.buf[CURS_POS(*curs)] && func(line.buf[CURS_POS(*curs)]))
	{
		if (!(line.cp % line.w.ws_col))
			tputs(tgetstr("do", NULL), 0, tputc);
		else
			tputs(tgetstr("nd", NULL), 0, tputc);
		++line.cp;
		++(*curs);
	}
}

void		skip_char(t_line line, size_t *curs, char dir, int (*func)(int c))
{
	if (dir == 'L')
		skip_left(line, curs, func);
	else
		skip_right(line, curs, func);
}

int		is_nospace(int c)
{
	return (!ft_isspace(c));
}

size_t		get_len_new_line(size_t len)
{
	size_t	base;

	base = INIT_LINE_SIZE;
	while (base < len)
		base *= 2;
	return (base);
}
