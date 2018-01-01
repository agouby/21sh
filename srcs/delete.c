#include "ft_sh.h"

static void	delete_char(char *buf, size_t pos, size_t len)
{
	while (pos != len)
	{
		buf[pos] = buf[pos + 1];
		pos++;
	}
}

void		delete_inside(t_line *line)
{
	delete_char(line->buf, CURS_POS(line->cp) - 1, line->i);
	tputs(tgetstr("sc", NULL), 0, tputc);
	write(STDOUT, line->buf + CURS_POS(line->cp) - 1, line->i - CURS_POS(line->cp));
	tputs(tgetstr("rc", NULL), 0, tputc);
}
