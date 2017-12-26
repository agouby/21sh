#include "line.h"

void	printable_pressed(int val)
{
	t_line *line;

	line = line_sgt(NULL);
	write(1, &val, 1);
	line->cp++;
}
