#include "lib_for_cub3D.h"

void ft_assign_ray_info(t_data	*game, t_ray_info ray_info, int x, float for_fisheye_effect);

void ft_create_rays(t_data	*game)
{
	t_ray_info ray_info;
	int x;
	float for_fisheye_effect;
	
	ray_info.ray_angle = game->direction_angle + DEGREE_30;
	if(ray_info.ray_angle > 2 * PI)
		ray_info.ray_angle -= 2 * PI;
	x = 0;
	while(x < SIZE_WIDTH_WINDOW_X)
	{	
		for_fisheye_effect = game->direction_angle - ray_info.ray_angle;
		if (for_fisheye_effect < 0)
			for_fisheye_effect += 2 * PI;
		if (for_fisheye_effect > 2 * PI)
			for_fisheye_effect -= 2 * PI;
		ft_assign_ray_info(game, ray_info, x, for_fisheye_effect);
		ray_info.ray_angle -= ONE_STEP_IN_RADIAN_FOR_FOV;
		if(ray_info.ray_angle < 0)
		{
			ray_info.ray_angle += 2 * PI;
		}
		x++;
	}
	return ;
}

void ft_assign_ray_info(t_data	*game, t_ray_info ray_info, int x, float for_fisheye_effect)
{
	ray_info.ray_to_vertical = ft_create_ray_vertical(game, ray_info.ray_angle, &(ray_info.wall_side_vertical), &(ray_info.point_of_texture_vertical));
	ray_info.ray_to_horizontal = ft_create_ray_horizontal(game, ray_info.ray_angle, &(ray_info.wall_side_horizontal), &(ray_info.point_of_texture_horizontal));
	if (ray_info.ray_to_vertical < ray_info.ray_to_horizontal)
	{
		game->rays_and_walls[x].ray_length = (ray_info.ray_to_vertical / (float)10) * cos(for_fisheye_effect);
		//printf("%f  %f\n", game->rays_and_walls[x].ray_length, ray_info.ray_to_vertical);
		game->rays_and_walls[x].wall_side = ray_info.wall_side_vertical;
		game->rays_and_walls[x].point_of_texture = ray_info.point_of_texture_vertical;
	}
	else
	{
		game->rays_and_walls[x].ray_length = (ray_info.ray_to_horizontal / 10) * cos(for_fisheye_effect);
		//printf("%f  %f\n", game->rays_and_walls[x].ray_length, ray_info.ray_to_horizontal);
		game->rays_and_walls[x].wall_side = ray_info.wall_side_horizontal;
		game->rays_and_walls[x].point_of_texture = ray_info.point_of_texture_horizontal;
	}
	return ;
}
