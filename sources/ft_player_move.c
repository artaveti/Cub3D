#include "lib_for_cub3D.h"

int ft_player_move(int key, t_data	*game)
{
	float degree_for_step_left_or_right;
	float ray_direction_x; // for draw, must delete
	float ray_direction_y; // for draw, must delete
	int player_has_moved;
	float check_vertical;
	float check_horizontal;
	int wall_side_vertical;
	int wall_side_horizontal;
	int direction_move;

	if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
	{	
		if (game->direction_angle > 0 && game->direction_angle < DEGREE_90)
		{
			direction_move = NE;
		}
		else if (game->direction_angle > DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE
				&& game->direction_angle < DEGREE_180 - ONE_THOUSANDTH_OF_ONE_DEGREE)
		{
			direction_move = NW;
		}
		else if (game->direction_angle > DEGREE_180 
				&& game->direction_angle < DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE)
		{
			direction_move = SW;
		}
		else if(game->direction_angle > DEGREE_270 
				&& game->direction_angle < DEGREE_360 - ONE_THOUSANDTH_OF_ONE_DEGREE)
		{
			direction_move = SE;
		}
		else
		{
			direction_move = 0;
		}
		ray_direction_y = game->player_coord_y - game->direction_y * 10; // for draw, must delete
		ray_direction_x = game->player_coord_x + game->direction_x * 10; // for draw, must delete
		mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00000000); // for player one pixel clear;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_direction_x, ray_direction_y, 0x00000000); // for direction one pixel clear;
		printf("angle:%f\n",game->direction_angle);
		printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
		printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);
		player_has_moved = 0;
		if (key == KEY_W)
		{
			printf("W\n");
			ft_move_by_degree(game, game->direction_angle, ONE_STEP_FOR_MOVE, &player_has_moved);
			if (player_has_moved == 0)
			{
				/*if (direction_move == 0)
				{
					break; 
				}*/
				check_vertical = ft_create_ray_vertical(game, game->direction_angle, &wall_side_vertical);
				check_horizontal = ft_create_ray_horizontal(game, game->direction_angle, &wall_side_horizontal);
				printf("VERTICAL:%f HORIZONTAL:%f\n", check_vertical, check_horizontal);
				if (check_vertical < check_horizontal)
				{
					if (game->direction_angle > 0 && game->direction_angle < DEGREE_180 - ONE_THOUSANDTH_OF_ONE_DEGREE)
					{
						ft_move_by_degree(game, DEGREE_90, (int)(ONE_STEP_FOR_MOVE), &player_has_moved);
					}
					else if (game->direction_angle > DEGREE_180 && game->direction_angle < DEGREE_360 - ONE_THOUSANDTH_OF_ONE_DEGREE)
					{
						ft_move_by_degree(game, DEGREE_270, &player_has_moved);
					}
				}
				else if (check_horizontal < check_vertical)
				{
					if (game->direction_angle > DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE && game->direction_angle < DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE)
					{
						ft_move_by_degree(game, DEGREE_180, &player_has_moved);
					}
					else if (game->direction_angle > DEGREE_270 || game->direction_angle < DEGREE_90)
					{
						ft_move_by_degree(game, DEGREE_0, &player_has_moved);
					}
				}
				else
				{

				}
			}
		}
		else if (key == KEY_S)
		{
			printf("S\n");
			game->player_coord_x -= game->direction_x * 10;
			game->player_coord_y += game->direction_y * 10;
			if(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
			{
				game->player_coord_x += game->direction_x * 10;
				game->player_coord_y -= game->direction_y * 10;
				while(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] != '1')
				{
					printf("FLOAT:%f  FLOAT:%f \n", game->player_coord_y, game->player_coord_x);
					printf("INT:%d  INT:%d \n", (int)game->player_coord_y, (int)game->player_coord_x);
					printf("INT/10: %d  INT/10: %d \n", (int)game->player_coord_y / 10, (int)game->player_coord_x /10);
					printf("Counter\n");
					game->player_coord_x -= game->direction_x;
					game->player_coord_y += game->direction_y;
					if (game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
					{
						game->player_coord_x += game->direction_x;
						game->player_coord_y -= game->direction_y;
						break ;
					}
					player_has_moved = 1;
				}
			}
		}
		else if (key == KEY_A)
		{
			printf("A\n");
			degree_for_step_left_or_right = game->direction_angle + DEGREE_90;
			if(degree_for_step_left_or_right > 2 * PI)
			{
				degree_for_step_left_or_right -= 2 * PI;
			}
			game->player_coord_x += cos(degree_for_step_left_or_right) * 10;
			game->player_coord_y -= sin(degree_for_step_left_or_right) * 10;
			if(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
			{
				game->player_coord_x -= cos(degree_for_step_left_or_right) * 10;
				game->player_coord_y += sin(degree_for_step_left_or_right) * 10;
				while(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] != '1')
				{
					printf("FLOAT:%f  FLOAT:%f \n", game->player_coord_y, game->player_coord_x);
					printf("INT:%d  INT:%d \n", (int)game->player_coord_y, (int)game->player_coord_x);
					printf("INT/10: %d  INT/10: %d \n", (int)game->player_coord_y / 10, (int)game->player_coord_x /10);
					printf("Counter\n");
					game->player_coord_x += cos(degree_for_step_left_or_right);
					game->player_coord_y -= sin(degree_for_step_left_or_right);
					if (game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
					{
						game->player_coord_x -= cos(degree_for_step_left_or_right);
						game->player_coord_y += sin(degree_for_step_left_or_right);
						break ;
					}
				}
			}
		}
		else if (key == KEY_D)
		{ 
			printf("D\n");
			degree_for_step_left_or_right = game->direction_angle - DEGREE_90;
			if(degree_for_step_left_or_right < 0)
			{
				degree_for_step_left_or_right += 2 * PI;
			}
			game->player_coord_x += cos(degree_for_step_left_or_right) * 10;
			game->player_coord_y -= sin(degree_for_step_left_or_right) * 10;
			if(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
			{
				game->player_coord_x -= cos(degree_for_step_left_or_right) * 10;
				game->player_coord_y += sin(degree_for_step_left_or_right) * 10;
				while(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] != '1')
				{
					printf("FLOAT:%f  FLOAT:%f \n", game->player_coord_y, game->player_coord_x);
					printf("INT:%d  INT:%d \n", (int)game->player_coord_y, (int)game->player_coord_x);
					printf("INT/10: %d  INT/10: %d \n", (int)game->player_coord_y / 10, (int)game->player_coord_x /10);
					printf("Counter\n");
					game->player_coord_x += cos(degree_for_step_left_or_right);
					game->player_coord_y -= sin(degree_for_step_left_or_right);
					if (game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
					{
						game->player_coord_x -= cos(degree_for_step_left_or_right);
						game->player_coord_y += sin(degree_for_step_left_or_right);
						break ;
					}
				}
			}
		}
		else if (key == ARROW_LEFT)
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
		ray_direction_y = game->player_coord_y - game->direction_y * 10; // for draw, must delete
		ray_direction_x = game->player_coord_x + game->direction_x * 10; // for draw, must delete
		mlx_pixel_put(game->mlx, game->mlx_win, game->player_coord_x, game->player_coord_y, 0x00FFFF00); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, ray_direction_x, ray_direction_y, 0x0000FF00); // for direction one pixel after move;
		printf("angle:%f\n",game->direction_angle);
		printf("direction_x:%f\ndirection_y:%f\n",game->direction_x, game->direction_y);
		printf("player_coord_x:%f\nplayer_coord_y:%f\n\n",game->player_coord_x, game->player_coord_y);
	}
	// clear pixels
	ft_create_rays(game);
	printf("FUNCTION END\n");
	// draw pixels
	ft_keypress_only_esc(key, game);
	return (0);
}

