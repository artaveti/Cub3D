/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_functions_five.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:47:57 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:14:07 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

unsigned int	create_trgb(char *t, char *r, char *g, char *b)
{
	unsigned int	result;

	result = simple_atoi(t) << 24 | simple_atoi(r) << 16
		| simple_atoi(g) << 8 | simple_atoi(b);
	return (result);
}

void	ft_free_struct_and_exit(t_data	*game)
{
	ft_free_for_struct(game);
	ft_put_error("Error: Wrong symbol in file");
	exit(EXIT_FAILURE);
	return ;
}

void	ft_for_ft_create_ray_horizontal(t_data	*game,
		t_ray_creat_info *ray_creat_info, float *point_of_texture)
{
	if (ray_creat_info->ray_length != game->ray_length_max)
	{
		ray_creat_info->ray_length = sqrt(pow(ray_creat_info->ray_end_x
					- game->player_coord_x, 2)
				+ pow(ray_creat_info->ray_end_y
					- game->player_coord_y, 2));
		*point_of_texture = fmod(ray_creat_info->ray_end_x,
				(float)10) / (float)10;
		if (*point_of_texture < 0)
			*point_of_texture = -*point_of_texture;
	}
	return ;
}

void	ft_for_ft_create_ray_vertical(t_data	*game,
			t_ray_creat_info *ray_creat_info, float *point_of_texture)
{
	if (ray_creat_info->ray_length != game->ray_length_max)
	{
		ray_creat_info->ray_length = sqrt(pow(ray_creat_info->ray_end_x
					- game->player_coord_x, 2)
				+ pow(ray_creat_info->ray_end_y
					- game->player_coord_y, 2));
		*point_of_texture = fmod((float)ray_creat_info->ray_end_y,
				(float)10) / (float)10;
		if (*point_of_texture < 0)
			*point_of_texture = -*point_of_texture;
	}
	return ;
}
