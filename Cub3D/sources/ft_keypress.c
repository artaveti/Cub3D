#include "lib_for_cub3D.h"

int	ft_keypress(int key, t_data *game)
{
	float ray_direction_x; // for draw, must delete
	float ray_direction_y; // for draw, must delete
	ray_direction_y = game->player_coord_y - game->direction_y * 10; // for draw, must delete
	ray_direction_x = game->player_coord_x + game->direction_x * 10; // for draw, must delete
	mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00000000); // for player one pixel clear;
	mlx_pixel_put(game->mlx, game->mlx_win, ray_direction_x, ray_direction_y, 0x00000000); // for direction one pixel clear;
	printf("angle:%f\n",game->direction_angle);
	printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
	printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);


	ft_change_player_coord(key, game);
	ft_change_direction_angle(key, game);
 	ft_keypress_only_esc(key, game);
	// clear pixels
	//system("leaks cub3D");
	mlx_clear_window(game->mlx, game->mlx_win);
	//  free(game->image_for_draw.img);
	//  free(game->image_for_draw.addr);
	mlx_destroy_image(game->mlx, game->image_for_draw.img);
	game->image_for_draw.img = mlx_new_image(game->mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y); // empty image
	game->image_for_draw.addr = mlx_get_data_addr(game->image_for_draw.img,
							&(game->image_for_draw.bits_per_pixel),
							&(game->image_for_draw.line_length),
							&(game->image_for_draw.endian)); // empty image
	ft_create_rays(game);
	ft_draw_image(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image_for_draw.img, 0, 0); // draw pixels


	/*int i;
	i = 0;
	while(i < SIZE_WIDTH_WINDOW_X)
	{	
		printf("I: %d\n", i);
		printf("RAY_LENGTH: %f\n", game->rays_and_walls[i].ray_length);
		printf("WALL_SIDE %d\n", game->rays_and_walls[i].wall_side);
		printf("POINT_OF_TEXTURE %d\n", game->rays_and_walls[i].point_of_texture);
		printf("\n");
		i++;
	}*/
	ray_direction_y = game->player_coord_y - game->direction_y * 10; // for draw, must delete
	ray_direction_x = game->player_coord_x + game->direction_x * 10; // for draw, must delete
	mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00FFFF00); // for player one pixel after move;
	mlx_pixel_put(game->mlx, game->mlx_win, ray_direction_x, ray_direction_y, 0x0000FF00); // for direction one pixel after move;
	printf("angle:%f\n",game->direction_angle);
	printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
	printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);

	return (0);
}



void ft_change_player_coord(int key, t_data	*game)
{

	float direction_angle;
	int player_has_moved;

	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
	{	
		player_has_moved = 0;
		direction_angle = 0;
		if (key == KEY_W)
		{
			printf("W\n");
			direction_angle = game->direction_angle;
			ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE, &player_has_moved);
			if (player_has_moved == 0)
			{
				ft_move_for_sliding(game, direction_angle, &player_has_moved);
			}
		}
		else if (key == KEY_S)
		{
			printf("S\n");
			direction_angle = game->direction_angle + DEGREE_180;
			if(direction_angle > 2 * PI)
			{
				direction_angle -= 2 * PI;
			}
			ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE, &player_has_moved);
			if (player_has_moved == 0)
			{
				ft_move_for_sliding(game, direction_angle, &player_has_moved);
			}
		}
		else if (key == KEY_A)
		{
			printf("A\n");
			direction_angle = game->direction_angle + DEGREE_90;
			if(direction_angle > 2 * PI)
			{
				direction_angle -= 2 * PI;
			}
			ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE, &player_has_moved);
			if (player_has_moved == 0)
			{
				ft_move_for_sliding(game, direction_angle, &player_has_moved);
			}
		}
		else if (key == KEY_D)
		{ 
			printf("D\n");
			direction_angle = game->direction_angle - DEGREE_90;
			if(direction_angle < 0)
			{
				direction_angle += 2 * PI;
			}
			ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE, &player_has_moved);
			printf("Player_Has_Moved: %d\n", player_has_moved);
			if (player_has_moved == 0)
			{
				ft_move_for_sliding(game, direction_angle, &player_has_moved);
			}
		}
	}
	return ;
}

void ft_change_direction_angle(int key, t_data	*game)
{
	if (key == ARROW_LEFT)
	{ 
		printf("Right\n");
		game->direction_angle += 0.1;
		if(game->direction_angle > 2 * PI)
		{
			game->direction_angle -= 2 * PI;
		}
		game->direction_x = cos(game->direction_angle);
		game->direction_y = sin(game->direction_angle);
	}
	else if (key == ARROW_RIGHT)
	{
		printf("Left\n");
		game->direction_angle -= 0.1;
		if(game->direction_angle < 0)
		{
			game->direction_angle += 2 * PI;
		}
		game->direction_x = cos(game->direction_angle);
		game->direction_y = sin(game->direction_angle);
	}
	return ;
}

int	ft_keypress_only_esc(int key, t_data	*game)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->mlx);
		// free structures (game)
		//system("leaks cub3D");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
