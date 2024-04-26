/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3D.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:23:59 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 19:26:48 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

int	main(int argc, char **argv)
{
	t_parsing	parsing;
	t_data		game;

	ft_parsing(&parsing, argc, argv);
	ft_assign_null_values_in_struct(&game);
	ft_creat_map_str(&game, argv);
	ft_chech_whitespaces_except_space_in_map(&game);
	ft_creat_splitted_map_and_check_only_space_in_line(&game);
	ft_assign_texture_color_only_map_height_width(&game);
	ft_check_texture_and_color_quant(&game);
	ft_malloc_for_rays_walls_textures(&game);
	ft_mlx_init_mlx_new_window(&game);
	ft_set_images_and_get_info(&game);
	ft_assign_values_in_struct(&game);
	ft_create_rays(&game);
	ft_draw_image(&game);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.image_for_draw.img,
		0, 0);
	mlx_key_hook (game.mlx_win, &ft_keypress, &game);
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	mlx_loop(game.mlx);
	ft_free_for_struct(&game);
	exit(EXIT_SUCCESS);
}
