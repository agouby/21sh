#include "ft_sh.h"

void	enter_pressed(int val)
{
	t_line	*line;

	(void)val;
	line = line_sgt(NULL);
	histo_add(&line->histo, histo_new(line->buf, line->i));
	ft_printf("\n%s\n", line->buf);
	//	write(1, "\n", 1);
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
	if (CURS_POS(line->cp) == line->i)
		return ;
	if (!(line->cp % line->w.ws_col))
		tputs(tgetstr("do", NULL), 0, tputc);
	else
		tputs(tgetstr("nd", NULL), 0, tputc);
	++line->cp;
}

void	up_pressed(void)
{
	t_line	*line;

	line = line_sgt(NULL);
	if (!line->histo_cur || !line->histo_cur->next)
		return ;
	home_pressed(0);
	tputs(tgetstr("ce", NULL), 0, tputc);
	modify_line(line, *line->histo_cur->next);
	write(STDOUT, line->buf, line->i);
	line->histo_cur = line->histo_cur->next;
	line_sgt(line);
}

void	down_pressed(void)
{
	t_line	*line;

	line = line_sgt(NULL);
	if (!line->histo_cur || !line->histo_cur->prev)
		return ;
	home_pressed(0);
	tputs(tgetstr("ce", NULL), 0, tputc);
	modify_line(line, *line->histo_cur->prev);
	write(STDOUT, line->buf, line->i);
	line->histo_cur = line->histo_cur->prev;
	line_sgt(line);
}

void	home_pressed(int val)
{
	t_line	*line;

	line = line_sgt(NULL);
	while (CURS_POS(line->cp) != 0)
	{
		if (!(line->cp % (line->w.ws_col)))
		{
			tputs(tgoto(tgetstr("ch", NULL), 0, line->w.ws_col), 0, tputc);
			tputs(tgetstr("up", NULL), 0, tputc);
		}
		tputs(tgetstr("le", NULL), 0, tputc);
		line->cp--;
	}
}

void	end_pressed(int val)
{
	t_line	*line;

	line = line_sgt(NULL);
	while (CURS_POS(line->cp) != line->i)
	{
		if (!(line->cp % line->w.ws_col))
			tputs(tgetstr("do", NULL), 0, tputc);
		else
			tputs(tgetstr("nd", NULL), 0, tputc);
		line->cp++;
	}
}

void	wleft_pressed(int val)
{
	t_line	*line;

	(void)val;
	line = line_sgt(NULL);
	if (!CURS_POS(line->cp))
		return ;
	if (ft_isspace(line->buf[CURS_POS(line->cp) - 1]))
		skip_char(*line, &line->cp, 'L', ft_isspace);
	skip_char(*line, &line->cp, 'L', is_nospace);
}

void	wright_pressed(int val)
{
	t_line	*line;

	(void)val;
	line = line_sgt(NULL);
	if (CURS_POS(line->cp) == line->i)
		return ;
	if (!ft_isspace(line->buf[CURS_POS(line->cp)]))
		skip_char(*line, &line->cp, 'R', is_nospace);
	skip_char(*line, &line->cp, 'R', ft_isspace);
}
