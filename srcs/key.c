#include "ft_sh.h"

int	get_key_index(int val)
{
	if (IS_PRINT(val))
		return (0);
	if (IS_ENTER(val))
		return (1);
	if (IS_DEL_F(val))
		return (2);
	if (IS_DEL_B(val))
		return (3);
	if (IS_ARROW(val))
		return (4);
	if (IS_HOME(val))
		return (5);
	if (IS_END(val))
		return (6);
	if (IS_WLEFT(val))
		return (7);
	if (IS_WRIGHT(val))
		return (8);
	return (-1);
}
