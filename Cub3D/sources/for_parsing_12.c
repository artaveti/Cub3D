#include "lib_for_cub3D.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*space;

	if (count == 0 || size == 0)
	{
		space = malloc(count * size);
		if (!space)
			return (0);
		return (space);
	}
	if (count > SIZE_MAX / size)
		return (0);
	space = malloc(count * size);
	if (!space)
		return (0);
	else
		ft_memset(space, '\0', count * size);
	return (space);
}

void	*ft_memset(void	*b, int c, size_t len)
{
	size_t			i;
	unsigned char	*mas;

	mas = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		mas[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
