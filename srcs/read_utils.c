void	combine_key_val(const char *buf, int *val)
{
	while (*buf)
		*val += (int)*(buf++);
}
