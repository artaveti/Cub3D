#include "lib_for_cub3D.h"

void	ft_assign_line_to_map(char	*dst, char *src, size_t num);

void copy_map_lines(int fd, t_game *Game)
{
    char *line;
    int line_count;

    check_map_size(Game);
	line = NULL;
	line_count = 0;
    while ((line = get_next_line(fd)))
    {
        if (inv_sym(line))
        {
            ft_put_error("Error: Invalid symbol found");
            //system("leaks cub3D");
            exit(EXIT_FAILURE);
        }
        Game->map[line_count] = ft_calloc(Game->width + 1, sizeof(char));
        if (Game->map[line_count] == NULL) 
        {
            ft_put_error("Error: Memory allocation failed");
            //system("leaks cub3D");
            exit(EXIT_FAILURE);
        }
		ft_assign_line_to_map(Game->map[line_count], line, ft_strlen(line));
		free(line);
        line_count++;
    }
	return ;
}

void	ft_assign_line_to_map(char	*dst, char *src, size_t num)
{
	size_t i;

	i = 0;
	while(i < num)
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}

void	ft_put_error(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		write(STDERR_FILENO, &string[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
	return ;
}

char	*ft_strdup(char	*s1)
{
	char	*dup;

	if (!s1 || s1 == NULL)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s1, ft_strlen(s1) + 1);
	return (dup);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (*src && i < dstsize - 1)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (len);
}
