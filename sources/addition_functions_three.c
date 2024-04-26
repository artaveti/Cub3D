/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_functions_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:50:02 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:39:04 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_assign_texture_or_color_n_s_w_e(t_data	*game,
			char **texture_or_color_splitted);
void	ft_assign_texture_or_color_e_f_c(t_data	*game,
			char **texture_or_color_splitted);

void	ft_assign_texture_color_only_map_height_width(t_data	*game)
{
	int		i;
	char	**texture_or_color_splitted;

	texture_or_color_splitted = NULL;
	i = 0;
	while (game->map_splitted_str[i] != NULL)
	{
		texture_or_color_splitted = ft_split(game->map_splitted_str[i], ' ');
		if (texture_or_color_splitted[0] == NULL)
		{
			ft_free_double_pointer_array(&texture_or_color_splitted);
			ft_free_struct_and_exit(game);
		}
		if (texture_or_color_splitted[0][0] == '1')
		{
			ft_free_double_pointer_array(&texture_or_color_splitted);
			break ;
		}
		ft_assign_texture_or_color_n_s_w_e(game, texture_or_color_splitted);
		ft_assign_texture_or_color_e_f_c(game, texture_or_color_splitted);
		ft_free_double_pointer_array(&texture_or_color_splitted);
		i++;
	}
	ft_assign_only_map_height_width(game, i);
	return ;
}

void	ft_assign_texture_or_color_n_s_w_e(t_data	*game,
			char **texture_or_color_splitted)
{
	if (texture_or_color_splitted[0][0] == 'N')
	{
		game->flags_textures_and_colors_quant.flag_north++;
		free(game->north_texture);
		game->north_texture = ft_strdup(texture_or_color_splitted[1]);
	}
	else if (texture_or_color_splitted[0][0] == 'S')
	{
		game->flags_textures_and_colors_quant.flag_south++;
		free(game->south_texture);
		game->south_texture = ft_strdup(texture_or_color_splitted[1]);
	}
	else if (texture_or_color_splitted[0][0] == 'W')
	{
		game->flags_textures_and_colors_quant.flag_west++;
		free(game->west_texture);
		game->west_texture = ft_strdup(texture_or_color_splitted[1]);
	}
	else if (texture_or_color_splitted[0][0] == 'E')
	{
		game->flags_textures_and_colors_quant.flag_east++;
		free(game->east_texture);
		game->east_texture = ft_strdup(texture_or_color_splitted[1]);
	}
	return ;
}

void	ft_assign_texture_or_color_e_f_c(t_data	*game,
			char **texture_or_color_splitted)
{
	if (texture_or_color_splitted[0][0] == 'F')
	{
		game->flags_textures_and_colors_quant.flag_floor++;
		free(game->floor_color_splitted);
		game->floor_color_splitted = ft_split(texture_or_color_splitted[1],
				',');
		game->floor_color = create_trgb("0",
				game->floor_color_splitted[0],
				game->floor_color_splitted[1],
				game->floor_color_splitted[2]);
	}
	else if (texture_or_color_splitted[0][0] == 'C')
	{
		game->flags_textures_and_colors_quant.flag_ceiling++;
		free(game->ceiling_color_splitted);
		game->ceiling_color_splitted = ft_split(texture_or_color_splitted[1],
				',');
		game->ceiling_color = create_trgb("0",
				game->ceiling_color_splitted[0],
				game->ceiling_color_splitted[1],
				game->ceiling_color_splitted[2]);
	}
	return ;
}

void	ft_memset_by_one_only_map(t_data	*game, int i)
{
	int	quant_for_map;
	int	len_width;

	quant_for_map = 0;
	while (game->map_splitted_str[i] != NULL)
	{
		len_width = ft_strlen(game->map_splitted_str[i]);
		if (len_width > game->map_max_width)
			game->map_max_width = len_width;
		quant_for_map++;
		i++;
	}
	game->map_array = malloc(sizeof(char *) * (quant_for_map + 1));
	if (game->map_array == NULL)
		ft_error_in_malloc_exit();
	ft_for_ft_memset_by_one_only_map(game, quant_for_map);
	return ;
}

void	ft_assign_only_map(t_data	*game, int i)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_splitted_str[i] != NULL)
	{
		x = 0;
		while (game->map_splitted_str[i][x] != '\0')
		{
			game->map_array[y][x] = game->map_splitted_str[i][x];
			if (game->map_array[y][x] == ' ')
				game->map_array[y][x] = '1';
			x++;
		}
		y++;
		i++;
	}
	return ;
}
