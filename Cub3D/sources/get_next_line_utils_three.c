#include "lib_for_cub3D.h"

int ft_assign_result_in_get_next_line(int fd, char	**result, int *i)
{
	*i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*result = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*result)
		return (0);
	return (1);
}

char	*ft_free_and_return_null_in_get_next_line(char		*result)
{
	free(result);
	return (NULL);
}

void ft_for_get_next_line(char *result, int *i, char *buf, int	*buf_index)
{
	result[*i] = buf[*buf_index];
	*i = *i + 1;
	*buf_index = *buf_index + 1;
	return ;
}
