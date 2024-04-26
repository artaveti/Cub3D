/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_12.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:45:14 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:39:52 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_assign_values_in_struct(t_data *game)
{
	game->ray_length_max = 1000;
	game->direction_x = cos(game->direction_angle);
	game->direction_y = sin(game->direction_angle);
	game->one_step_in_radian_for_fov = FOV_RADIAN / SIZE_WIDTH_WINDOW_X;
	return ;
}

void	ft_free_line_and_exit(char *line)
{
	free(line);
	ft_put_error("Error: Map is empty");
	exit(EXIT_FAILURE);
	return ;
}

void	ft_error_in_malloc_exit(void)
{
	ft_put_error("Error: Memory allocation failed");
	exit(EXIT_FAILURE);
}
