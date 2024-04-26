/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:35:02 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 14:56:34 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	check_attr_count(t_parsing *parsing)
{
	if (parsing->attr.count.f_count != 1 || parsing->attr.count.c_count != 1)
	{
		ft_put_error("Error: ivalid count F || C");
		exit(EXIT_FAILURE);
	}
	if (!(parsing->attr.count.no_count >= 1
			&& parsing->attr.count.so_count >= 1
			&& parsing->attr.count.we_count >= 1
			&& parsing->attr.count.ea_count >= 1))
	{
		ft_put_error("Error: ivalid count NO || SO || WE || EA");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	is_attr(char *line)
{
	if (ft_strlen(line) < 2 && (line[0] != 'F' && line[0] != 'C'))
		return (0);
	if ((ft_strncmp(line, "NO", ft_strlen(line)) == 0)
		|| ft_strncmp(line, "SO", ft_strlen(line)) == 0
		|| ft_strncmp(line, "WE", ft_strlen(line)) == 0
		|| ft_strncmp(line, "EA", ft_strlen(line)) == 0
		|| ft_strncmp(line, "F", ft_strlen(line)) == 0
		|| ft_strncmp(line, "C", ft_strlen(line)) == 0)
		return (1);
	return (0);
}

void	init_attributes(t_parsing *parsing)
{
	parsing->map_first_line = NULL;
	parsing->attr_line = 0;
	parsing->height = 1;
	parsing->width = 0;
	parsing->attr.count.no_count = 0;
	parsing->attr.count.so_count = 0;
	parsing->attr.count.we_count = 0;
	parsing->attr.count.ea_count = 0;
	parsing->attr.count.f_count = 0;
	parsing->attr.count.c_count = 0;
	parsing->attr.attr_count = 0;
	parsing->attr.direction_angle = NULL;
	parsing->attr.so = NULL;
	parsing->attr.we = NULL;
	parsing->attr.no = NULL;
	parsing->attr.ea = NULL;
	parsing->attr.f = NULL;
	parsing->attr.c = NULL;
	return ;
}

void	pars_attributes(t_parsing *parsing, int fd, int *map_start)
{
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strdup(line);
		if (!is_attribute(parsing, line))
		{
			parsing->map_first_line = ft_strdup(tmp);
			free(line);
			free(tmp);
			break ;
		}
		else
		{
			free(line);
			free(tmp);
			line = get_next_line(fd);
			(*map_start)++;
		}
	}
	if (!line)
		ft_free_line_and_exit(line);
	return ;
}

void	free_attributes(t_parsing *parsing)
{
	free(parsing->map_first_line);
	free(parsing->attr.direction_angle);
	free(parsing->attr.so);
	free(parsing->attr.we);
	free(parsing->attr.no);
	free(parsing->attr.ea);
	free(parsing->attr.f);
	free(parsing->attr.c);
	return ;
}
