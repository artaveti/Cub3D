#include "lib_for_cub3D.h"

size_t	ft_strlen(const	char *s)
{
	size_t	i;

	i = 0;
	if (!s[0])
		return (0);
	while (s[i])
		i++;
	return (i);
}