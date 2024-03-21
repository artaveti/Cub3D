#include "lib_for_cub3D.h"

unsigned int	create_trgb(char *t, char *r, char *g, char *b)
{
	unsigned int result;

	result = simple_atoi(t) << 24 | simple_atoi(r) << 16 | simple_atoi(g) << 8 | simple_atoi(b);
	return (result);
}
