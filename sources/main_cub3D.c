#include "lib_for_cub3D.h"

void ft_draw_squares(t_data	*game, int width, int height);

int	main(int argc, char **argv)
{

	t_data	game;
	ft_assign_null_values_in_struct(&game);

// float ray_direction_x; // for draw must delete
// float ray_direction_y; // for draw must delete
	//(void)argc;
	//(void)argv;
	ft_check_argc_and_name(argc, argv);
	ft_check_map(argv, &game);
	game.rays_and_walls = malloc(sizeof(t_ray_and_wall) * SIZE_WIDTH_WINDOW_X);
	if (game.rays_and_walls == NULL)
	{
		exit(EXIT_FAILURE);
	}
	game.textures = malloc(sizeof(t_image_info) * 4);
	if (game.textures == NULL)
	{
		ft_free_for_struct(&game);
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
		ft_free_for_struct(&game);
		exit(EXIT_FAILURE);
	}
	game.mlx_win = mlx_new_window(game.mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y, "./cub3D");
	if (game.mlx_win == NULL)
	{
		//mlx_destroy_window(game.mlx, game.mlx_win);
		ft_free_for_struct(&game);
		exit(EXIT_FAILURE);
	}
 	ft_set_images_and_get_info(&game);

// ft_draw_squares(&game, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y); // for draw must delete

	game.map_width = 8;  // must get from map //multiply by 10
	game.map_height = 8; // must get from map //multiply by 10
	game.ray_length_max = (float)sqrt(pow(game.map_width - 2, 2) + pow(game.map_height - 2, 2)) * 10; // 1000000
	game.player_coord_x = 15; // * 10 + 5
	game.player_coord_y = 15; // * 10 + 5
	game.direction_angle = DEGREE_0; // NO, SO, WE, EA
	game.direction_x = cos(game.direction_angle); //x
	game.direction_y = sin(game.direction_angle); //y
	ft_create_rays(&game); // draw first picture
	ft_draw_image(&game); // draw first picture
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.image_for_draw.img, 0, 0); // draw first picture

// mlx_pixel_put(game.mlx, game.mlx_win, game.player_coord_x, game.player_coord_y, 0x00FFFF00); // for player start coordinates;
// ray_direction_y = game.player_coord_y - game.direction_y * 10; // for draw must delete 
// ray_direction_x = game.player_coord_x + game.direction_x * 10; // for draw must delete 
// mlx_pixel_put(game.mlx, game.mlx_win, ray_direction_x, ray_direction_y, 0x0000FF00); // for direction start coordinates;

	mlx_key_hook (game.mlx_win, &ft_keypress, &game); // player move
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	free(game.mlx_win);
	free(game.mlx);
	//free all allocated memory
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

void ft_draw_squares(t_data	*game, int width, int height)
{
	int x;
	int y;
	int new_y;

	y = 0;
	while(y < height)
	{
		x = 0;
		while(x < width)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x, y, 0x00606060); // for ft_draw_squares;
			if (x % 10 == 0)
			{
				new_y = 0;
				while(new_y < height)
				{
					mlx_pixel_put(game->mlx, game->mlx_win, x, new_y, 0x00606060); // for ft_draw_squares;
					new_y++;
				}
			}
			x++;
		}
		y += 10;
	}
	return ;
}



