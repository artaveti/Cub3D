/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:10:35 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 18:16:01 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_change_player_coord_front_back(int key, t_data	*game);
void	ft_change_player_coord_left_right(int key, t_data	*game);
void	ft_change_direction_angle(int key, t_data	*game);
int		ft_keypress_only_esc(int key, t_data	*game);

int	ft_keypress(int key, t_data *game)
{
	ft_change_player_coord_front_back(key, game);
	ft_change_player_coord_left_right(key, game);
	ft_change_direction_angle(key, game);
	ft_keypress_only_esc(key, game);
	mlx_destroy_image(game->mlx, game->image_for_draw.img);
	game->image_for_draw.img = mlx_new_image(game->mlx, SIZE_WIDTH_WINDOW_X,
			SIZE_HEIGHT_WINDOW_Y);
	game->image_for_draw.addr = mlx_get_data_addr(game->image_for_draw.img,
			&(game->image_for_draw.bits_per_pixel),
			&(game->image_for_draw.line_length),
			&(game->image_for_draw.endian));
	ft_create_rays(game);
	ft_draw_image(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->image_for_draw.img,
		0, 0);
	return (0);
}

void	ft_change_player_coord_front_back(int key, t_data	*game)
{
	float	direction_angle;
	int		player_has_moved;

	player_has_moved = 0;
	direction_angle = 0;
	if (key == KEY_W)
	{
		direction_angle = game->direction_angle;
		ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE,
			&player_has_moved);
	}
	else if (key == KEY_S)
	{
		direction_angle = game->direction_angle + DEGREE_180;
		if (direction_angle > 2 * PI)
			direction_angle -= 2 * PI;
		ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE,
			&player_has_moved);
	}
	if (player_has_moved == 0 && (key == KEY_W || key == KEY_S))
		ft_move_for_sliding(game, direction_angle, &player_has_moved);
	return ;
}

void	ft_change_player_coord_left_right(int key, t_data	*game)
{
	float	direction_angle;
	int		player_has_moved;

	player_has_moved = 0;
	direction_angle = 0;
	if (key == KEY_A)
	{
		direction_angle = game->direction_angle + DEGREE_90;
		if (direction_angle > 2 * PI)
			direction_angle -= 2 * PI;
		ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE,
			&player_has_moved);
	}
	else if (key == KEY_D)
	{
		direction_angle = game->direction_angle - DEGREE_90;
		if (direction_angle < 0)
			direction_angle += 2 * PI;
		ft_move_by_degree(game, direction_angle, ONE_STEP_FOR_MOVE,
			&player_has_moved);
	}
	if (player_has_moved == 0 && (key == KEY_A || key == KEY_D))
		ft_move_for_sliding(game, direction_angle, &player_has_moved);
	return ;
}

void	ft_change_direction_angle(int key, t_data	*game)
{
	if (key == ARROW_LEFT)
	{
		game->direction_angle += 0.1;
		if (game->direction_angle > 2 * PI)
			game->direction_angle -= 2 * PI;
		game->direction_x = cos(game->direction_angle);
		game->direction_y = sin(game->direction_angle);
	}
	else if (key == ARROW_RIGHT)
	{
		game->direction_angle -= 0.1;
		if (game->direction_angle < 0)
			game->direction_angle += 2 * PI;
		game->direction_x = cos(game->direction_angle);
		game->direction_y = sin(game->direction_angle);
	}
	return ;
}

int	ft_keypress_only_esc(int key, t_data	*game)
{
	if (key == KEY_ESC)
	{
		ft_free_for_struct(game);
		printf("Exit\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
