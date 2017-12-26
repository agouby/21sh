#include "ft_sh.h"

void	resize(int sig)
{
	t_line	*line;

	(void)sig;
	line = line_sgt(NULL);
	ioctl(STDIN, TIOCGWINSZ, &line->w);
	line_sgt(line);
}
