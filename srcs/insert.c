#include "ft_sh.h"

static void	insert_char(char *buf, char c, size_t pos, size_t len)
{
	while (pos != len)
	{
		buf[len] = buf[len - 1];
		len--;
	}
	buf[pos] = c;
}

void		insert_back(t_line *line, int val)
{
	write(STDOUT, &val, 1);
	line->buf[line->i] = (char)val;
	++line->i;
}

void		insert_inside(t_line *line, int val)
{
	write(STDOUT, &val, 1);
	insert_char(line->buf, (char)val, CURS_POS, line->i);
	tputs(tgetstr("sc", NULL), 0, tputc);
	write(STDOUT, line->buf + CURS_POS + 1, line->i - CURS_POS + 1);
	tputs(tgetstr("rc", NULL), 0, tputc);
	++line->i;
}
