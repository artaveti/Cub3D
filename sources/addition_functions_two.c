/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_functions_two.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:15:44 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:14:12 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_creat_map_str(t_data	*game, char **argv)
{
	int	read_result;
	int	quant_for_malloc;
	int	fd_map;

	read_result = 1;
	quant_for_malloc = 0;
	fd_map = open(argv[1], O_RDONLY);
	game->map_str = ft_strdup(" ");
	while (read_result > 0)
	{
		read_result = read(fd_map, game->map_str, 1);
		if (read_result > 0)
			quant_for_malloc++;
	}
	close(fd_map);
	free(game->map_str);
	game->map_str = NULL;
	fd_map = open(argv[1], O_RDONLY);
	game->map_str = malloc(sizeof(char) * quant_for_malloc + 1);
	if (game->map_str == NULL)
		ft_error_in_malloc_exit();
	read(fd_map, game->map_str, quant_for_malloc);
	game->map_str[quant_for_malloc] = '\0';
	return ;
}

void	ft_assign_height_width(t_data	*game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map_array[y] != NULL)
		y++;
	x = 0;
	while (game->map_array[0][x] != '\0')
		x++;
	game->map_height = y;
	game->map_width = x;
	if (game->map_height > 60 || game->map_width > 60)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: Large map size");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_assign_player_coord(t_data	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map_array[y] != NULL)
	{
		x = 0;
		while (game->map_array[y][x] != '\0')
		{
			if (game->map_array[y][x] == 'N'
				|| game->map_array[y][x] == 'S'
				|| game->map_array[y][x] == 'W'
				|| game->map_array[y][x] == 'E')
			{
				ft_assign_direction_angle(game, game->map_array[y][x]);
				game->player_coord_y = y * 10 + 5;
				game->player_coord_x = x * 10 + 5;
				break ;
			}
			x++;
		}
		y++;
	}
	return ;
}

void	ft_assign_only_map_height_width(t_data	*game, int i)
{
	ft_memset_by_one_only_map(game, i);
	ft_assign_only_map(game, i);
	ft_assign_height_width(game);
	ft_assign_player_coord(game);
	return ;
}

void	ft_assign_null_in_struct_flags_textures_and_colors_quant(t_data	*game)
{
	game->flags_textures_and_colors_quant.flag_north = 0;
	game->flags_textures_and_colors_quant.flag_south = 0;
	game->flags_textures_and_colors_quant.flag_west = 0;
	game->flags_textures_and_colors_quant.flag_east = 0;
	game->flags_textures_and_colors_quant.flag_floor = 0;
	game->flags_textures_and_colors_quant.flag_ceiling = 0;
	return ;
}
