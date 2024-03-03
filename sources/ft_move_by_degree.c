#include "lib_for_cub3D.h"

void	ft_move_by_degree( t_data	*game, float   direction_angle, int one_step, int *player_has_moved)
{
	float	direction_x;
	float	direction_y;
	int 	move_counter;

	direction_x = cos(direction_angle);
	direction_y = sin(direction_angle);
	move_counter = 0;
	while(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] != '1' && move_counter < one_step)
	{
		// printf("Y_FLOAT:%f  X_FLOAT:%f \n", game->player_coord_y, game->player_coord_x);
		// printf("Y_INT:%d  X_INT:%d \n", (int)game->player_coord_y, (int)game->player_coord_x);
		// printf("Y_INT/10: %d  X_INT/10: %d \n", (int)game->player_coord_y / 10, (int)game->player_coord_x /10);
		// printf("Counter\n");
		game->player_coord_x += direction_x;
		game->player_coord_y -= direction_y;
		if (game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
		{
			game->player_coord_x -= direction_x;
			game->player_coord_y += direction_y;
			return ;
		}
		*player_has_moved = 1;
		move_counter++;
	}
	return ;
}

void	ft_move_for_sliding(t_data	*game, float   direction_angle, int *player_has_moved)
{
	float ray_to_vertical;
	float ray_to_horizontal;
	int wall_side_vertical;
	int wall_side_horizontal;
	int point_of_texture_vertical;
	int point_of_texture_horizontal;

	ray_to_vertical = ft_create_ray_vertical(game, direction_angle, &wall_side_vertical, &point_of_texture_vertical);
	ray_to_horizontal = ft_create_ray_horizontal(game, direction_angle, &wall_side_horizontal, &point_of_texture_horizontal);
	printf("VERTICAL:%f HORIZONTAL:%f\n", ray_to_vertical, ray_to_horizontal);
	printf("DIRECTION_ANGLE:%f \n",direction_angle);
	if (ray_to_vertical < ray_to_horizontal)
	{
		if (direction_angle > 0 && direction_angle < DEGREE_180 - ONE_THOUSANDTH_OF_ONE_DEGREE)
		{
			ft_move_by_degree(game, DEGREE_90, (int)(sin(direction_angle) * ONE_STEP_FOR_MOVE), player_has_moved);
		}
		else if (direction_angle > DEGREE_180 && direction_angle < DEGREE_360 - ONE_THOUSANDTH_OF_ONE_DEGREE)
		{
			ft_move_by_degree(game, DEGREE_270, (int)(sin(direction_angle) * -(ONE_STEP_FOR_MOVE)), player_has_moved);
		}
	}
	else
	{
		if (direction_angle > DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE && direction_angle < DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE)
		{
			ft_move_by_degree(game, DEGREE_180, (int)(cos(direction_angle) * -(ONE_STEP_FOR_MOVE)), player_has_moved);
		}
		else if (direction_angle > DEGREE_270 || direction_angle < DEGREE_90)
		{
			ft_move_by_degree(game, DEGREE_0, (int)(cos(direction_angle) * ONE_STEP_FOR_MOVE), player_has_moved);
		}
	}
	return ;
}
