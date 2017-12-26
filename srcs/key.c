#include "ft_sh.h"

int	get_key_index(int val)
{
	if (IS_PRINT(val))
		return (0);
	else if (IS_ENTER(val))
		return (1);
	else if (IS_DEL_F(val))
		return (2);
	else if (IS_DEL_B(val))
		return (3);
	else if (IS_ARROW(val))
		return (4);
	return (-1);
}
