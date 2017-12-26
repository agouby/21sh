#include "ft_sh.h"

int	err_sgt(int data)
{
	static int	sgt = 0;

	if (data)
		sgt = data;
	return (sgt);
}

void	*line_sgt(void *data)
{
	static void	*sgt = NULL;

	if (data)
		sgt = data;
	return (sgt);
}

void	*arrow_sgt(int b)
{
	static void	(*sgt[4])(void);

	if (b)
	{
		sgt[0] = &up_pressed;
		sgt[1] = &down_pressed;
		sgt[2] = &right_pressed;
		sgt[3] = &left_pressed;
	}
	return (sgt);
}
