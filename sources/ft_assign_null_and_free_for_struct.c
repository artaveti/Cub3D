/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_null_and_free_for_struct.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:20:08 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 13:04:22 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_assign_null_values_in_struct(t_data	*game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->map_str = NULL;
	game->map_splitted_str = NULL;
	game->map_array = NULL;
	game->north_texture = NULL;
	game->south_texture = NULL;
	game->west_texture = NULL;
	game->east_texture = NULL;
	game->floor_color_splitted = NULL;
	game->ceiling_color_splitted = NULL;
	ft_assign_null_in_struct_flags_textures_and_colors_quant(game);
	game->map_max_width = 0;
	game->map_width = 0;
	game->map_height = 0;
	game->ray_length_max = 0;
	game->player_coord_x = 0;
	game->player_coord_y = 0;
	game->direction_angle = 0;
	game->direction_x = 0;
	game->direction_y = 0;
	game->textures = NULL;
	ft_assign_null_values_in_struct_image_info(&(game->image_for_draw));
	game->rays_and_walls = NULL;
	return ;
}

void	ft_assign_null_values_in_struct_image_info(t_image_info *image_info)
{
	image_info->img = NULL;
	image_info->addr = NULL;
	image_info->bits_per_pixel = 0;
	image_info->line_length = 0;
	image_info->endian = 0;
	image_info->width = 0;
	image_info->height = 0;
	return ;
}

void	ft_free_for_struct(t_data	*game)
{
	free(game->map_str);
	ft_free_double_pointer_array(&(game->map_splitted_str));
	ft_free_double_pointer_array(&(game->map_array));
	free(game->north_texture);
	free(game->south_texture);
	free(game->west_texture);
	free(game->east_texture);
	ft_free_double_pointer_array(&(game->floor_color_splitted));
	ft_free_double_pointer_array(&(game->ceiling_color_splitted));
	free(game->rays_and_walls);
	if (game->mlx != NULL && game->mlx_win != NULL)
		mlx_destroy_window(game->mlx, game->mlx_win);
	return ;
}

void	ft_free_double_pointer_array(char ***array)
{
	int		i;
	char	**tmp;

	if (!*array || *array == NULL)
		return ;
	tmp = *array;
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
	return ;
}

void	ft_free_struct_image_info(t_image_info *image_info)
{
	free(image_info->img);
	image_info->img = NULL;
	free(image_info->addr);
	image_info->addr = NULL;
	return ;
}
