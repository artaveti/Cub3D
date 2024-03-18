#include "lib_for_cub3D.h"

// if (SIZE_HEIGHT_WINDOW_Y == 0 || SIZE_WIDTH_WINDOW_X == 0) free, exit;
// map size check ???
// problem whem map more than 10x10 

int	main(int argc, char **argv)
{
	t_game	Game;
	t_data	game;

	// ft_check_argc_and_name(argc, argv);
    // ft_get_map(argv[1], &Game);
    // check_attr_count(&Game);
    // check_attr_identif(&Game);
    // ft_check_map(&Game);
	//free_map(&Game);
    //free_attributes(&Game);

	ft_assign_null_values_in_struct(&game);
	game.rays_and_walls = malloc(sizeof(t_ray_and_wall) * SIZE_WIDTH_WINDOW_X);
	if (game.rays_and_walls == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_put_error("Error: in malloc");
		exit(EXIT_FAILURE);
	}
	game.textures = malloc(sizeof(t_image_info) * 4);
	if (game.textures == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_free_for_struct(&game);
		ft_put_error("Error: in malloc");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_assign_null_values_in_struct_image_info(&(game.textures[0]));
		ft_assign_null_values_in_struct_image_info(&(game.textures[1]));
		ft_assign_null_values_in_struct_image_info(&(game.textures[2]));
		ft_assign_null_values_in_struct_image_info(&(game.textures[3]));
	}
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_free_for_struct(&game);
		ft_put_error("Error: in mlx_init");
		exit(EXIT_FAILURE);
	}
	game.mlx_win = mlx_new_window(game.mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y, "./cub3D");
	if (game.mlx_win == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_free_for_struct(&game);
		ft_put_error("Error: in mlx_new_window");
		exit(EXIT_FAILURE);
	}
 	ft_set_images_and_get_info(&game, &Game);
//printf("X:%d Y:%d W:%d H:%d\n",Game.player.x, Game.player.y, Game.width, Game.height);
	game.map_width = Game.width - 1;
	game.map_height = Game.height;
	game.splitted_str = Game.map;
	game.ray_length_max = (float)sqrt(pow(game.map_width - 2, 2) + pow(game.map_height - 2, 2)) * 10;
	game.player_coord_x = Game.player.x * 10 + 5; // * 10 + 5
	game.player_coord_y = Game.player.y * 10 + 5; // * 10 + 5
	ft_assign_direction_angle(&game, &Game);
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
