#include "line.h"

# include "ft_sh.h"

t_histo		*histo_new(char *name, size_t name_len)
{
	t_histo	*new;

	if (!(new = (t_histo *)malloc(sizeof(t_histo))))
		ft_memerr();
	new->name = ft_strdup(name);
	new->name_len = name_len;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		histo_add(t_histo **old, t_histo *new)
{
	if (!*old)
	{
		new->next = *old;
		*old = new;
		return ;
	}
	new->next = *old;
	new->next->prev = new;
	*old = new;
}

// TO DELETE

void		histo_print(t_histo *list)
{
	while (list)
	{
		ft_printf("{%s} --> {%d}\n", list->name, list->name_len);
		list = list->next;
	}
}
