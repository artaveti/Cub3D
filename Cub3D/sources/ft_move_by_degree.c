#include "lib_for_cub3D.h"

void ft_assing_in_ft_move_for_sliding(t_data	*game, t_move_sliding_info *sliding, float   direction_angle);

void	ft_move_by_degree( t_data	*game, float   direction_angle, int one_step, int *player_has_moved)
{
	float	direction_x;
	float	direction_y;
	int 	move_counter;
	t_move_sliding_info move;
	//printf("ANGLE:(%f)\n", direction_angle);
ft_assing_in_ft_move_for_sliding(game, &move, direction_angle);
if (move.ray_to_vertical <= 1 || move.ray_to_horizontal <= 1)
{
	return;
}
	direction_x = cos(direction_angle);
	direction_y = sin(direction_angle);
	printf("direction_x:(%f) direction_y:(%f)\n", direction_x, direction_y);
	move_counter = 0;
	while(move_counter < one_step)
	{
		game->player_coord_x += direction_x;
		game->player_coord_y -= direction_y;
ft_assing_in_ft_move_for_sliding(game, &move, direction_angle);
//printf("vertical: %f horizontal %f \n",move.ray_to_vertical, move.ray_to_horizontal);
if (move.ray_to_vertical <= 1 || move.ray_to_horizontal <= 1)
{
	game->player_coord_x -= direction_x;
	game->player_coord_y += direction_y;
	return;
}
		// if (game->map_array[(int)game->player_coord_y
		// 	/ 10][(int)game->player_coord_x / 10] == '1')
		// {
		// 	game->player_coord_x -= direction_x * 2;
		// 	game->player_coord_y += direction_y * 2;
		// 	return ;
		// }
		*player_has_moved = 1;
		move_counter++;
	}
ft_assing_in_ft_move_for_sliding(game, &move, direction_angle);
printf("vertical: %f horizontal %f \n",move.ray_to_vertical, move.ray_to_horizontal);
	return ;
}

void	ft_move_for_sliding(t_data	*game, float   direction_angle, int *player_has_moved)
{
	t_move_sliding_info sliding;

	ft_assing_in_ft_move_for_sliding(game, &sliding, direction_angle);
	if (sliding.ray_to_vertical < sliding.ray_to_horizontal)
	{
		if (direction_angle > 0 && direction_angle
				< DEGREE_180 - ONE_THOUSANDTH_OF_ONE_DEGREE)
			ft_move_by_degree(game, DEGREE_90, (int)(sin(direction_angle)
								* ONE_STEP_FOR_MOVE), player_has_moved);
		else if (direction_angle > DEGREE_180 && direction_angle
					< DEGREE_360 - ONE_THOUSANDTH_OF_ONE_DEGREE)
			ft_move_by_degree(game, DEGREE_270, (int)(sin(direction_angle)
								* -(ONE_STEP_FOR_MOVE)), player_has_moved);
	}
	else
	{
		if (direction_angle > DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE
			&& direction_angle < DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE)
			ft_move_by_degree(game, DEGREE_180, (int)(cos(direction_angle)
							* -(ONE_STEP_FOR_MOVE)), player_has_moved);
		else if (direction_angle > DEGREE_270 || direction_angle < DEGREE_90)
			ft_move_by_degree(game, DEGREE_0, (int)(cos(direction_angle)
							* ONE_STEP_FOR_MOVE), player_has_moved);
	}
	return ;
}

void ft_assing_in_ft_move_for_sliding(t_data	*game, t_move_sliding_info *sliding, float   direction_angle)
{
	sliding->ray_to_vertical = ft_create_ray_vertical(game,
						direction_angle,
						&(sliding->wall_side_vertical),
						&(sliding->point_of_texture_vertical));
	sliding->ray_to_horizontal = ft_create_ray_horizontal(game,
						direction_angle,
						&(sliding->wall_side_horizontal),
						&(sliding->point_of_texture_horizontal));
	return ;
}