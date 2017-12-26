#include "ft_sh.h"

static int	fill_read_buffer(t_key *key)
{
	if ((key->ret = read(STDIN, key->buf, 4)) == -1)
	{
		err_sgt(ERR_READ);
		return (-1);
	}
	key->buf[key->ret] = '\0';
	return (0);
}

int		read_input(t_key *key)
{
	key->val = 0;
	if (fill_read_buffer(key) == -1)
		return (-1);
	combine_key_val(key->buf, &key->val);
	return (0);
}
