/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:01:52 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 16:21:24 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

int	ft_for_check_color_one(size_t length, char *color)
{
	int		comma_count;
	size_t	i;

	comma_count = 0;
	i = 0;
	while (i < length)
	{
		if (color[i] == ',')
			comma_count++;
		i++;
	}
	if (color[length - 1] == ',' || comma_count != 2)
	{
		free(color);
		return (0);
	}
	return (1);
}

int	ft_for_check_color_two(int counter, char *color)
{
	if (counter != 3)
	{
		free(color);
		return (0);
	}
	free(color);
	return (1);
}

int	check_color_f(char *line)
{
	char	*token;
	char	*color;
	size_t	length;
	int		counter;

	counter = 0;
	color = ft_strdup(line);
	length = ft_strlen(color);
	if (ft_for_check_color_one(length, color) == 0)
		return (0);
	token = my_strtok_f(color, ",");
	while (token != NULL)
	{
		if (invalid_color(token))
		{
			free(color);
			return (0);
		}
		token = my_strtok_f(NULL, ",");
		counter++;
	}
	return (ft_for_check_color_two(counter, color));
}

int	check_color_c(char *line)
{
	char	*token;
	char	*color;
	size_t	length;
	int		counter;

	counter = 0;
	color = ft_strdup(line);
	length = ft_strlen(color);
	if (ft_for_check_color_one(length, color) == 0)
		return (0);
	token = my_strtok_c(color, ",");
	while (token != NULL)
	{
		if (invalid_color(token))
		{
			free(color);
			return (0);
		}
		token = my_strtok_c(NULL, ",");
		counter++;
	}
	return (ft_for_check_color_two(counter, color));
}

void	check_attr_identif(t_parsing *parsing)
{
	if (!check_color_f(parsing->attr.f))
	{
		ft_put_error("Invalid color");
		exit(EXIT_FAILURE);
	}
	else if (!check_color_c(parsing->attr.c))
	{
		ft_put_error("Invalid color");
		exit(EXIT_FAILURE);
	}
	return ;
}
