#include "lib_for_cub3D.h"

int ft_player_move(int key, t_data	*game);
void ft_create_rays(t_data	*game);
//int	ft_keypress_only_esc(int key, t_data	*game);
//int	ft_close_with_cross(t_data	*game)


int	main(int argc, char **argv)
{

t_data	game;

int map_width;
int map_height;
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
	
	//map_width = ft_strlen(game.splitted_str_1[0]);
	//map_height = game.splitted_str_1; // must count lines quant
	
	map_width = 8;
	map_height = 8;
	
	game.player_coord_x = 10 + 5;
	game.player_coord_y = 10 + 5;
	game.angle = 0;
	game.direction_x = cos(game.angle); //x
	game.direction_y = sin(game.angle); //y

	//int i;
	//i = 0;
	//int key;
	/*while(i < 3)
	{
		printf("Enter direction key: \n");
		scanf("%d", &key);
		ft_player_move(key, &game);
		//ft_create_rays(&game);
		i++;
	}*/
	mlx_key_hook (game.mlx_win, &ft_player_move, &game); // player move
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	free(game.mlx);
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

int ft_player_move(int key, t_data	*game)
{
	float degree_for_step_left_or_right;

	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
	{	
		printf("angle:%f\n",game->angle);
		printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
		printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);
		if (key == KEY_W)
		{
			printf("W\n");
			game->player_coord_x += game->direction_x * 10;
			game->player_coord_y -= game->direction_y * 10;
		}
		else if (key == KEY_S)
		{ 
			printf("S\n");
			game->player_coord_x -= game->direction_x * 10;
			game->player_coord_y += game->direction_y * 10;
		}
		else if (key == KEY_A)
		{
			printf("A\n");
			degree_for_step_left_or_right = game->angle - DEGREE_90;
			if(degree_for_step_left_or_right < 0)
			{
				degree_for_step_left_or_right += 2 * PI;
			}
			game->player_coord_x += cos(degree_for_step_left_or_right) * 10;
			game->player_coord_y += sin(degree_for_step_left_or_right) * 10;
		}
		else if (key == KEY_D)
		{ 
			printf("D\n");
			degree_for_step_left_or_right = game->angle + DEGREE_90;
			if(degree_for_step_left_or_right > 2 * PI)
			{
				degree_for_step_left_or_right -= 2 * PI;
			}
			game->player_coord_x += cos(degree_for_step_left_or_right) * 10;
			game->player_coord_y += sin(degree_for_step_left_or_right) * 10;
		}
		else if (key == ARROW_RIGHT)
		{
			printf("Left\n");
			game->angle -= 0.1;
			if(game->angle < 0)
			{
				game->angle += 2 * PI;
			}
			game->direction_x = cos(game->angle);
			game->direction_y = sin(game->angle);
		}
		else if (key == ARROW_LEFT)
		{ 
			printf("Right\n");
			game->angle += 0.1;
			if(game->angle > 2 * PI)
			{
				game->angle -= 2 * PI;
			}
			game->direction_x = cos(game->angle);
			game->direction_y = sin(game->angle);
		}
		mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00FFFF00); // for player one pixel after move;
		printf("angle:%f\n",game->angle);
		printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
		printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);
	}
	ft_create_rays(game);
	//ft_keypress_only_esc(key, game);
	return (0);
}

void ft_create_rays(t_data	*game)
{
	float ray_start_x;
	float ray_start_y;
	float ray_end_x;
	float ray_end_y;
	float distance_x;
	//float distance_y;

	ray_start_x = game->player_coord_x;
	ray_start_y = game->player_coord_y;
	ray_end_x = 0;
	ray_end_y = 0;
	printf("Angle*********************************%f\n", game->angle);
	if(game->angle < DEGREE_90 && game->angle > 0)
	{
		printf("I am here\n");
		ray_end_x = (int)game->player_coord_x - 5 + 10;
		distance_x = ray_end_x - game->player_coord_x;
		ray_end_y = game->player_coord_y - tan(game->angle) * distance_x;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_start_x, ray_start_y, 0x00FFFFFF); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for player one pixel after move;
	}
	return ;
}


/*int	ft_keypress_only_esc(int key, t_data	*game)
{
	if (key == KEY_ESC)
	{
		//mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->mlx);
		//system("leaks cub3D");
		exit(EXIT_SUCCESS);
	}
	return (0);
}*/

/*int	ft_close_with_cross(t_data	*game)
{
	//mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}*/
