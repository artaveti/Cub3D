#include "lib_for_cub3D.h"

char	*ft_gnl_strjoin(char	*left_str, char	*buff)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (0);
	str = malloc(sizeof(char) * (ft_gstrlen(left_str) + ft_gstrlen(buff) + 1));
	if (!str)
		return (0);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_gstrlen(left_str) + ft_gstrlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_read_to_left_str(int fd, char	*left_str)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE_FOR_GNL + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_gstrchr(left_str, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE_FOR_GNL);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		left_str = ft_gnl_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*ft_get_line(char	*left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (0);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char	*left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free (left_str);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_gstrlen(left_str) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free (left_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE_FOR_GNL <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
