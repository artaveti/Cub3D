/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:01:43 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 14:08:25 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_assign_line_to_map(char *dst, char *src, size_t num);

void	copy_map_lines(int fd, t_parsing	*parsing)
{
	char	*line;
	int		line_count;

	check_map_size(parsing);
	line_count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		inv_sym(line);
		parsing->map[line_count] = ft_calloc(parsing->width + 1, sizeof(char));
		if (parsing->map[line_count] == NULL)
		{
			ft_put_error("Error: Memory allocation failed");
			exit(EXIT_FAILURE);
		}
		ft_assign_line_to_map(parsing->map[line_count], line, ft_strlen(line));
		free(line);
		line = get_next_line(fd);
		line_count++;
	}
	return ;
}

void	ft_assign_line_to_map(char *dst, char *src, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
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
	{
		ft_error_in_malloc_exit();
		return (NULL);
	}
	dup = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
	{
		ft_error_in_malloc_exit();
		return (NULL);
	}
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
