/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_by_degree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:16:32 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 19:02:00 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_assing_in_ft_move_for_sliding(t_data	*game,
			t_move_sliding_info *sliding, float direction_angle);
void	ft_step_back_if_close_to_the_wall(t_data	*game,
			t_move_sliding_info *move, float direction_x, float direction_y);

void	ft_move_by_degree( t_data	*game, float direction_angle,
			int one_step, int *player_has_moved)
{
	float				direction_x;
	float				direction_y;
	int					move_counter;
	t_move_sliding_info	move;

	ft_assing_in_ft_move_for_sliding(game, &move, direction_angle);
	if (move.ray_to_vertical < 1.1 || move.ray_to_horizontal < 1.1)
		return ;
	direction_x = cos(direction_angle);
	direction_y = sin(direction_angle);
	move_counter = 0;
	while (move_counter < one_step)
	{
		game->player_coord_x += direction_x;
		game->player_coord_y -= direction_y;
		ft_assing_in_ft_move_for_sliding(game, &move, direction_angle);
		if (move.ray_to_vertical < 1.1 || move.ray_to_horizontal < 1.1)
			return (ft_step_back_if_close_to_the_wall(game, &move,
					direction_x, direction_y));
		*player_has_moved = 1;
		move_counter++;
	}
	return ;
}

void	ft_move_for_sliding(t_data *game, float direction_angle,
			int *player_has_moved)
{
	t_move_sliding_info	sliding;

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

void	ft_assing_in_ft_move_for_sliding(t_data	*game,
			t_move_sliding_info *sliding, float direction_angle)
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

void	ft_step_back_if_close_to_the_wall(t_data	*game,
			t_move_sliding_info *move, float direction_x, float direction_y)
{
	float	difference_for_step_back;

	difference_for_step_back = 0;
	if (move->ray_to_vertical <= move->ray_to_horizontal)
		difference_for_step_back = 1 - move->ray_to_vertical;
	else
		difference_for_step_back = 1 - move->ray_to_horizontal;
	game->player_coord_x -= (direction_x * difference_for_step_back);
	game->player_coord_y += (direction_y * difference_for_step_back);
	return ;
}
