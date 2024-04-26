/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:21:40 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 14:00:01 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	free_map(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (!parsing->map)
		return ;
	if (parsing->map != NULL)
	{
		while (i < parsing->height)
		{
			free(parsing->map[i]);
			i++;
		}
		free(parsing->map);
	}
	return ;
}

void	get_map_size(int fd, t_parsing	*parsing)
{
	int		max_width;
	int		line_len;
	char	*line;

	max_width = (int)ft_strlen(parsing->map_first_line);
	parsing->width = max_width;
	line_len = 0;
	line = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		parsing->height++;
		line_len = ft_strlen(line);
		if (line_len > max_width)
		{
			max_width = line_len;
			parsing->width = max_width;
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return ;
}

void	allocate_map_memory(t_parsing	*parsing)
{
	parsing->map = (char **)ft_calloc(parsing->height, sizeof(char *));
	if (parsing->map == NULL)
	{
		ft_put_error("Error: Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	check_map_size(t_parsing	*parsing)
{
	if (parsing->height < 3 || parsing->width < 3)
	{
		ft_put_error("Error: Invalid map size");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_get_map(char	*argv, t_parsing	*parsing)
{
	int		fd;
	int		map_start;
	char	*line;

	map_start = 0;
	init_attributes(parsing);
	parsing->attr.direction_angle = ft_strdup(" ");
	check_file_exists(argv, &fd);
	pars_attributes(parsing, fd, &map_start);
	get_map_size(fd, parsing);
	close(fd);
	allocate_map_memory(parsing);
	check_file_exists(argv, &fd);
	line = get_next_line(fd);
	while (line != NULL && map_start > 1)
	{
		free(line);
		line = get_next_line(fd);
		map_start--;
	}
	free(line);
	copy_map_lines(fd, parsing);
	close(fd);
	return ;
}
