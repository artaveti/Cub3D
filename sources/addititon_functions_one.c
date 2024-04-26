/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addititon_functions_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:18:36 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:14:39 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_chech_whitespaces_except_space_in_map(t_data	*game)
{
	int	i;

	i = 0;
	while (game->map_str[i] != '\0')
	{
		if (game->map_str[i] == '\t' || game->map_str[i] == '\v'
			|| game->map_str[i] == '\f' || game->map_str[i] == '\r')
		{
			ft_free_for_struct(game);
			ft_put_error("Error: Wrong symbol in file");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	ft_creat_splitted_map_and_check_only_space_in_line(t_data	*game)
{
	int	i;
	int	j;
	int	char_except_space;

	game->map_splitted_str = ft_split(game->map_str, '\n');
	i = 0;
	while (game->map_splitted_str[i] != NULL)
	{
		j = 0;
		char_except_space = 0;
		while (game->map_splitted_str[i][j] != '\0')
		{
			if (game->map_splitted_str[i][j] != ' ')
				char_except_space = 1;
			j++;
		}
		if (char_except_space == 0)
		{
			ft_free_for_struct(game);
			ft_put_error("Error: Wrong symbol in file");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	ft_assign_ray_creat_info(t_ray_creat_info *ray_creat_info)
{
	ray_creat_info->ray_length = 0;
	ray_creat_info->ray_end_x = 0;
	ray_creat_info->ray_end_y = 0;
	return ;
}

void	ft_assign_direction_angle(t_data *game, char c)
{
	if (c == 'N')
		game->direction_angle = DEGREE_90;
	else if (c == 'S')
		game->direction_angle = DEGREE_270;
	else if (c == 'W')
		game->direction_angle = DEGREE_180;
	else if (c == 'E')
		game->direction_angle = DEGREE_0;
	return ;
}

int	ft_close_with_cross(t_data	*game)
{
	ft_free_for_struct(game);
	printf("Exit\n");
	exit(EXIT_SUCCESS);
}
