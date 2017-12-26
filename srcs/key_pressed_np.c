#include "ft_sh.h"

void	enter_pressed(int val)
{
	t_line	*line;
	(void)val;
	write(1, "\n", 1);
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
	if (line->cp == PROMPT_LEN)
		return ;
	tputs(tgetstr("le", NULL), 0, tputc);
	--line->cp;
}

void	right_pressed(void)
{
	t_line *line;

	line = line_sgt(NULL);
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
