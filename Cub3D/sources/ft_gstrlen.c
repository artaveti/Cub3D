#include "lib_for_cub3D.h"

size_t	ft_gstrlen(char	*s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
