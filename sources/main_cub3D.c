#include "lib_for_cub3D.h"

void ft_draw_squares(t_data	*game, int width, int height);
int ft_player_move(int key, t_data	*game);
void ft_create_rays(t_data	*game);
float ft_create_ray_vertical(t_data	*game, float angle_of_ray, int *wall_side_horizontal);
float ft_create_ray_horizontal(t_data	*game, float angle_of_ray, int *wall_side_horizontal);
int	ft_keypress_only_esc(int key, t_data	*game);
//int	ft_close_with_cross(t_data	*game)

//stugel zroneri bajanelu depqery tang-i ev cotang-i hashvarki jamanak

int	main(int argc, char **argv)
{

	t_data	game;
	game.rays_and_walls = malloc(sizeof(t_ray_and_wall) * SIZE_WIDTH_WINDOW_X);

float ray_direction_x; // for draw must delete 
float ray_direction_y; // for draw must delete 
	//(void)argc;
	//(void)argv;
	ft_check_argc_and_name(argc, argv);
	ft_check_map(argv, &game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(EXIT_FAILURE);
	game.mlx_win = mlx_new_window(game.mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y, "./cub3D");
	if (game.mlx_win == NULL)
		exit(EXIT_FAILURE);
	
ft_draw_squares(&game, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y);
	game.map_width = 20;  // must get from map
	game.map_height = 20; // must get from map
	
	game.player_coord_x = 25;
	game.player_coord_y = 25;
	
	game.direction_angle = DEGREE_90 * 0.3; // NO, SO, WE, EA
	game.direction_x = cos(game.direction_angle); //x
	game.direction_y = sin(game.direction_angle); //y
	
	mlx_pixel_put(game.mlx, game.mlx_win, game.player_coord_x, game.player_coord_y, 0x00FFFF00); // for player start coordinates;
	
	ray_direction_y = game.player_coord_y - game.direction_y * 10; // for draw must delete 
	ray_direction_x = game.player_coord_x + game.direction_x * 10; // for draw must delete 
	
	mlx_pixel_put(game.mlx, game.mlx_win, ray_direction_x, ray_direction_y, 0x0000FF00); // for direction start coordinates;
	mlx_key_hook (game.mlx_win, &ft_player_move, &game); // player move
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	free(game.mlx);
	// free in structures;
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

int	ft_keypress_only_esc(int key, t_data	*game)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->mlx);
		//system("leaks cub3D");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/*int	ft_close_with_cross(t_data	*game)
{
	//mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}*/

