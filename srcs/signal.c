#include "ft_sh.h"

void	init_signals(void)
{
	signal(SIGWINCH, &resize);
}
