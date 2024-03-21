#include "lib_for_cub3D.h"

// if (SIZE_HEIGHT_WINDOW_Y == 0 || SIZE_WIDTH_WINDOW_X == 0) free, exit;
// must check and use difference of ray_length

int	main(int argc, char **argv)
{
	t_game	Game;
	t_data	game;

	ft_parsing(&Game, argc, argv);
//system("leaks cub3D");
	ft_assign_null_values_in_struct(&game);
	ft_creat_map_str(&game, argv);
	ft_chech_whitespaces_except_space_in_map(&game);
	ft_creat_splitted_map_and_check_only_space_in_line(&game);
	ft_assign_texture_color_only_map_height_width(&game);
	ft_check_texture_and_color_quant(&game);
	ft_malloc_for_rays_walls_textures(&game);
	ft_mlx_init_mlx_new_window(&game);
 	ft_set_images_and_get_info(&game);
	game.ray_length_max = 1000;
	game.direction_x = cos(game.direction_angle); //x
	game.direction_y = sin(game.direction_angle); //y
	ft_create_rays(&game); // draw first picture
	ft_draw_image(&game); // draw first picture
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.image_for_draw.img, 0, 0); // draw first picture
	mlx_key_hook (game.mlx_win, &ft_keypress, &game); // player move
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	mlx_loop(game.mlx);
	ft_free_for_struct(&game);
	exit(EXIT_SUCCESS);
}

	// printf("N:%d\n", game.flags_textures_and_colors_quant.flag_north);
	// printf("S:%d\n", game.flags_textures_and_colors_quant.flag_south);
	// printf("W:%d\n", game.flags_textures_and_colors_quant.flag_west);
	// printf("E:%d\n", game.flags_textures_and_colors_quant.flag_east);
	// printf("F:%d\n", game.flags_textures_and_colors_quant.flag_floor);
	// printf("C:%d\n", game.flags_textures_and_colors_quant.flag_ceiling);

// int p;
// p = 0;
// while(game.map_array[p] != NULL)
// {
// 	printf("game->map_splitted_str[%d](%s)\n", p, game.map_array[p]);
// 	p++;
// }


// int p;
// int q;
// p = 0;
// q = 0;
// while(game.map_splitted_str[p] != NULL)
// {
// 	q = 0;
// 	while(game.map_splitted_str[p][q] != '\0')
// 	{
// 		printf("game->map_splitted_str[%d][%d](%c)\n", p, q, game.map_splitted_str[p][q]);
// 		q++;
// 	}
// 	printf("game->map_splitted_str[%d](%s)\n", p, game.map_splitted_str[p]);
// 	p++;
// }