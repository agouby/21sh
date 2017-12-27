#include "ft_sh.h"

void	printable_pressed(int val)
{
	t_line *line;

	line = line_sgt(NULL);
	if (line->i + 1 == line->len)
		resize_line_buf(line);
	if (line->i == CURS_POS)
		insert_back(line, val);
	else
		insert_inside(line, val);
	if (!(line->cp % line->w.ws_col))
		tputs(tgetstr("do", NULL), 0, tputc);
	++line->cp;
}

void	del_f_pressed(int val)
{
	t_line *line;

	line = line_sgt(NULL);
	if (!CURS_POS)
		return ;
	if (!(line->cp % line->w.ws_col - 1))
	{
		tputs(tgetstr("up", NULL), 0, tputc);
		tputs(tgoto(tgetstr("ch", NULL), 0, line->w.ws_col), 0, tputc);
	}
	else
		tputs(tgetstr("le", NULL), 0, tputc);
	tputs(tgetstr("cd", NULL), 0, tputc);
	if (CURS_POS == line->i)
		line->buf[line->i - 1] = '\0';
	else
		delete_inside(line);
	--line->i;
	--line->cp;
}
