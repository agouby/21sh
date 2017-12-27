#include "ft_sh.h"

void	enter_pressed(int val)
{
	t_line	*line;

	(void)val;
	line = line_sgt(NULL);
//	write(1, "\n", 1);
	ft_printf("\n        {%s}\n", line->buf);
}

void	arrow_pressed(int val)
{
	void	(**arrow_func)(void);

	arrow_func = arrow_sgt(0);
	arrow_func[val - 183]();
}

void	left_pressed(void)
{
	t_line *line;

	line = line_sgt(NULL);
	if (line->cp == PROMPT_LEN_UI)
		return ;
	if (!(line->cp % line->w.ws_col - 1))
	{
		tputs(tgetstr("up", NULL), 0, tputc);
		tputs(tgoto(tgetstr("ch", NULL), 0, line->w.ws_col), 0, tputc);
	}
	else
		tputs(tgetstr("le", NULL), 0, tputc);
	--line->cp;
}

void	right_pressed(void)
{
	t_line *line;

	line = line_sgt(NULL);
	if (CURS_POS == line->i)
		return ;
	if (!(line->cp % line->w.ws_col))
		tputs(tgetstr("do", NULL), 0, tputc);
	else
		tputs(tgetstr("nd", NULL), 0, tputc);
	++line->cp;
}

void	up_pressed(void)
{
	;
}

void	down_pressed(void)
{
	;
}
