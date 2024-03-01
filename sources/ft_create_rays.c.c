#include "lib_for_cub3D.h"

void ft_create_rays(t_data	*game)
{
	float vertical_ray;
	//float horizontal_ray;
	float angle_of_ray;
	int wall_side_vertical;
	//int wall_side_horizontal;
	int i;
	
	angle_of_ray = game->direction_angle + DEGREE_30;
	if(angle_of_ray > 2 * PI)
	{
		angle_of_ray -= 2 * PI;
	}
	printf("DIRECTION_ANGLE %f\n", game->direction_angle);
	printf("DEGREE_30 %f\n", DEGREE_30);
	printf("ANGLE %f\n", angle_of_ray);
	i = 0;
	while(i < SIZE_WIDTH_WINDOW_X)
	{	
		vertical_ray = ft_create_ray_vertical(game, angle_of_ray, &wall_side_vertical);
		//horizontal_ray = ft_create_ray_horizontal(game, angle_of_ray, &wall_side_horizontal);
		/*if (vertical_ray < horizontal_ray)
		{
			game->rays_and_walls[i][0] = vertical_ray;
			game->rays_and_walls[i][1] = wall_side_vertical;
		}
		else
		{
			game->rays_and_walls[i][0] = horizontal_ray;
			game->rays_and_walls[i][1] = wall_side_horizontal;
		}*/
		angle_of_ray -= ONE_STEP_IN_RADIAN_FOR_FOV;
		if(angle_of_ray < 0)
		{
			angle_of_ray += 2 * PI;
		}
		printf("DEGREE_30 %f\n", DEGREE_30);
		printf("DIRECTION_ANGLE %f\n", game->direction_angle);
		printf("ANGLE %f\n", angle_of_ray);
		i++;
	}
	return ;
}

