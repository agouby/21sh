#include "ft_sh.h"

static int	fill_read_buffer(t_key *key)
{
	if ((key->ret = read(STDIN, key->buf, READ_LEN)) == -1)
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


static void	empty(int val)
{
	(void)val;
}

void		init_process_input(void (*process_input[NB_ENTRIES])(int val))
{
	process_input[0] = &printable_pressed;
	process_input[1] = &enter_pressed;
	process_input[2] = &del_f_pressed;
	process_input[3] = &empty;
	process_input[4] = &arrow_pressed;
	process_input[5] = &home_pressed;
	process_input[6] = &end_pressed;
	process_input[7] = &wleft_pressed;
	process_input[8] = &wright_pressed;
}
