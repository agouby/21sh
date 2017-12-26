#include "ft_sh.h"

static void	empty(int val)
{
	(void)val;
}

void	init_process_input(void (*process_input[NB_ENTRIES])(int val))
{
	process_input[0] = &printable_pressed;
	process_input[1] = &enter_pressed;
	process_input[2] = &empty;
	process_input[3] = &empty;
	process_input[4] = &arrow_pressed;
	process_input[5] = &empty;
	process_input[6] = &empty;
}

void	init_line(t_line *line)
{
	line->buf = NULL;
	line->i = 0;
	line->cp = PROMPT_LEN_UI;
	ioctl(STDIN, TIOCGWINSZ, &line->w);
	line_sgt(line);
}
