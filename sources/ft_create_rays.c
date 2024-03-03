#include "lib_for_cub3D.h"

void ft_create_rays(t_data	*game)
{
	float direction_angle;
	float ray_to_vertical;
	float ray_to_horizontal;
	int wall_side_vertical;
	int wall_side_horizontal;
	int point_of_texture_vertical;
	int point_of_texture_horizontal;
	int i;
	
	direction_angle = game->direction_angle + DEGREE_30;
	if(direction_angle > 2 * PI)
	{
		direction_angle -= 2 * PI;
	}
	// printf("DIRECTION_ANGLE %f\n", game->direction_angle);
	// printf("DEGREE_30 %f\n", DEGREE_30);
	// printf("ANGLE %f\n", direction_angle);
	i = 0;
	while(i < SIZE_WIDTH_WINDOW_X)
	{	
		ray_to_vertical = ft_create_ray_vertical(game, direction_angle, &wall_side_vertical, &point_of_texture_vertical);
		ray_to_horizontal = ft_create_ray_horizontal(game, direction_angle, &wall_side_horizontal, &point_of_texture_horizontal);
		printf("I: %d\n", i);
		printf("VERTICAL: %f\n", ray_to_vertical);
		printf("HORIZONTAL: %f\n", ray_to_horizontal);
		printf("\n");
		if (ray_to_vertical < ray_to_horizontal)
		{
			game->rays_and_walls[i].ray_length = ray_to_vertical;
			game->rays_and_walls[i].wall_side = wall_side_vertical;
			game->rays_and_walls[i].point_of_texture = point_of_texture_vertical;
		}
		else
		{
			game->rays_and_walls[i].ray_length = ray_to_horizontal;
			game->rays_and_walls[i].wall_side = wall_side_horizontal;
			game->rays_and_walls[i].point_of_texture = point_of_texture_horizontal;
		}
		direction_angle -= ONE_STEP_IN_RADIAN_FOR_FOV;
		if(direction_angle < 0)
		{
			direction_angle += 2 * PI;
		}
		// printf("DEGREE_30 %f\n", DEGREE_30);
		// printf("DIRECTION_ANGLE %f\n", game->direction_angle);
		// printf("ANGLE %f\n", direction_angle);
		i++;
	}
	return ;
}
