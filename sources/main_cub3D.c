#include "lib_for_cub3D.h"

void ft_draw_squares(t_data	*game, int width, int height);
int ft_player_move(int key, t_data	*game);
void ft_create_rays(t_data	*game);
void ft_create_rays_check_horizontal(t_data	*game);
//int	ft_keypress_only_esc(int key, t_data	*game);
//int	ft_close_with_cross(t_data	*game)

//stugel zroneri bajanelu depqery tang-i ev cotang-i hashvarki jamanak

int	main(int argc, char **argv)
{

// printf("DEGREE_0:%d\n", DEGREE_0);
// printf("DEGREE_90:%f\n", DEGREE_90);
// printf("DEGREE_180:%f\n", DEGREE_180);
// printf("DEGREE_270:%f\n", DEGREE_270);
// printf("DEGREE_360:%f\n", DEGREE_360);

t_data	game;


int map_width;
int map_height;
float ray_direction_x;
float ray_direction_y;
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
	//map_width = ft_strlen(game.splitted_str_1[0]);
	//map_height = game.splitted_str_1; // must count lines quant
	
	map_width = 4;
	map_height = 6;
	
	game.player_coord_x = 100;
	game.player_coord_y = 100;
	game.angle = DEGREE_90 * 0.3;
	game.direction_x = cos(game.angle); //x
	game.direction_y = sin(game.angle); //y
	mlx_pixel_put(game.mlx, game.mlx_win, game.player_coord_x, game.player_coord_y, 0x00FFFF00); // for player one pixel after move;
	ray_direction_y = game.player_coord_y - game.direction_y * 10;
	ray_direction_x = game.player_coord_x + game.direction_x * 10;
	mlx_pixel_put(game.mlx, game.mlx_win, ray_direction_x, ray_direction_y, 0x0000FF00); // for direction one pixel after move;
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
	float ray_direction_x;
	float ray_direction_y;

	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
	{	
		ray_direction_y = game->player_coord_y - game->direction_y * 10;
		ray_direction_x = game->player_coord_x + game->direction_x * 10;
		mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00000000); // for player one pixel clear;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_direction_x, ray_direction_y, 0x00000000); // for direction one pixel after move;
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
			degree_for_step_left_or_right = game->angle + DEGREE_90;
			if(degree_for_step_left_or_right > 2 * PI)
			{
				degree_for_step_left_or_right -= 2 * PI;
			}
			game->player_coord_x += cos(degree_for_step_left_or_right) * 10;
			game->player_coord_y -= sin(degree_for_step_left_or_right) * 10;
		}
		else if (key == KEY_D)
		{ 
			printf("D\n");
			degree_for_step_left_or_right = game->angle - DEGREE_90;
			if(degree_for_step_left_or_right < 0)
			{
				degree_for_step_left_or_right += 2 * PI;
			}
			game->player_coord_x += cos(degree_for_step_left_or_right) * 10;
			game->player_coord_y -= sin(degree_for_step_left_or_right) * 10;
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
		mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00FFFF00); // for player one pixel after move;
		ray_direction_y = game->player_coord_y - game->direction_y * 10;
		ray_direction_x = game->player_coord_x + game->direction_x * 10;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_direction_x, ray_direction_y, 0x0000FF00); // for direction one pixel after move;
		printf("angle:%f\n",game->angle);
		printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
		printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);
	}
	ft_create_rays(game);
	ft_create_rays_check_horizontal(game);
	//ft_keypress_only_esc(key, game);
	return (0);
}

void ft_create_rays(t_data	*game)
{
	float ray_start_x;
	float ray_start_y;
	static float ray_end_x;
	static float ray_end_y;
	float distance_x;
	int remainder;
	//float distance_y;
	ray_start_x = game->player_coord_x;
	ray_start_y = game->player_coord_y;
	mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00000000);
	//ray_end_x = 0;
	//ray_end_y = 0;
	//printf("Angle*********************************%f\n", game->angle);
	if(game->angle <= DEGREE_90 || game->angle >= DEGREE_270)
	{
		printf("LESS THAN 90 AND MORE THAN 270\n");
		remainder = (int)game->player_coord_x % 10;
		ray_end_x = (int)game->player_coord_x - remainder + 10;
		distance_x = ray_end_x - game->player_coord_x;
		ray_end_y = game->player_coord_y - tan(game->angle) * distance_x;
		//mlx_pixel_put(game->mlx, game->mlx_win, ray_start_x, ray_start_y, 0x00FFFFFF); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for player one pixel after move;
	}
	else
	{
		printf("MORE THAN 90 AND LESS THAN 270\n");
		remainder = (int)game->player_coord_x % 10;
		ray_end_x = (int)game->player_coord_x - remainder - 10;
		distance_x = ray_end_x - game->player_coord_x;
		ray_end_y = game->player_coord_y - tan(game->angle) * distance_x;
		//mlx_pixel_put(game->mlx, game->mlx_win, ray_start_x, ray_start_y, 0x00FFFFFF); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for player one pixel after move;
	}
	return ;
}

void ft_create_rays_check_horizontal(t_data	*game)
{
	float ray_start_x;
	float ray_start_y;
	static float ray_end_x;
	static float ray_end_y;
	//float distance_x;
	float distance_y;
	int remainder;
	//float distance_y;
	ray_start_x = game->player_coord_x;
	ray_start_y = game->player_coord_y;
	mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00000000);
	//ray_end_x = 0;
	//ray_end_y = 0;
	//printf("Angle*********************************%f\n", game->angle);
	if(game->angle >= DEGREE_0 && game->angle <= DEGREE_180)
	{
		printf("MORE THAN 0 AND LESS THAN 180\n");
		remainder = (int)game->player_coord_y % 10;
		ray_end_y = (int)game->player_coord_y - remainder - 10;
		distance_y = game->player_coord_y - ray_end_y;
		ray_end_x = game->player_coord_x + 1 / tan(game->angle) * distance_y;
		//mlx_pixel_put(game->mlx, game->mlx_win, ray_start_x, ray_start_y, 0x00FFFFFF); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for player one pixel after move;
	}
	else
	{
		printf("MORE THAN 180 AND LESS THAN 360\n");
		remainder = (int)game->player_coord_y % 10;
		ray_end_y = (int)game->player_coord_y - remainder + 10;
		distance_y = game->player_coord_y - ray_end_y;
		ray_end_x = game->player_coord_x + 1 / tan(game->angle) * distance_y;
		//mlx_pixel_put(game->mlx, game->mlx_win, ray_start_x, ray_start_y, 0x00FFFFFF); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for player one pixel after move;
	}
	return ;
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



/*if (game->angle >= DEGREE_0 && game->angle <= DEGREE_180)
{
	ray_direction_y = game->player_coord_y - game->direction_y * 10;
}
else
{
	ray_direction_y = game->player_coord_y - game->direction_y * 10;
}
if (game->angle >= DEGREE_90 && game->angle <= DEGREE_270)
{
	ray_direction_x = game->player_coord_x + game->direction_x * 10;
}
else
{
	ray_direction_x = game->player_coord_x + game->direction_x * 10;
}*/