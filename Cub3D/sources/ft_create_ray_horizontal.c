#include "lib_for_cub3D.h"

void	ft_count_raylen_less_180_more_0(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray);
void	ft_loop_for_ft_count_raylen_less_180_more_0(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray);
void	ft_count_raylen_less_360_more_180(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray);
void	ft_loop_for_ft_count_raylen_less_360_more_180(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray);
void	ft_for_ft_create_ray_horizontal(t_data	*game, t_ray_creat_info *ray_creat_info, float *point_of_texture);

float ft_create_ray_horizontal(t_data	*game, float angle_of_ray, int *wall_side_horizontal, float *point_of_texture)
{
	t_ray_creat_info ray_creat_info;


	*point_of_texture = 0;
	ft_assign_ray_creat_info(&ray_creat_info);
	ray_creat_info.remainder = (int)game->player_coord_y % 10;
	if(angle_of_ray > DEGREE_0 && angle_of_ray < DEGREE_180 - ONE_THOUSANDTH_OF_ONE_DEGREE)
	{
		*wall_side_horizontal = SO;
		ft_count_raylen_less_180_more_0(game, &ray_creat_info, angle_of_ray);
	}
	else if(angle_of_ray < DEGREE_360 - ONE_THOUSANDTH_OF_ONE_DEGREE
			&& angle_of_ray > DEGREE_180)
	{
		*wall_side_horizontal = NO;
		ft_count_raylen_less_360_more_180(game, &ray_creat_info, angle_of_ray);
	}
	else
	{
		//printf("I am here\n");
		*wall_side_horizontal = NO;
		*point_of_texture = 0;
		return game->ray_length_max;
	}
	ft_for_ft_create_ray_horizontal(game, &ray_creat_info, point_of_texture);
	return ray_creat_info.ray_length;
}

void	ft_count_raylen_less_180_more_0(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray)
{
	ray_creat_info->ray_end_y = (int)game->player_coord_y - ray_creat_info->remainder - 0.00001;
	printf("y(%f)\n", ray_creat_info->ray_end_y);
	ray_creat_info->distance = game->player_coord_y - ray_creat_info->ray_end_y;
	if(angle_of_ray > DEGREE_90 && angle_of_ray < DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE)
		ray_creat_info->ray_end_x = game->player_coord_x;
	else
		ray_creat_info->ray_end_x = game->player_coord_x + (1 / tan(angle_of_ray)) * ray_creat_info->distance;
	// printf("REMAINDER:%d\n", ray_creat_info->remainder);
	// printf("RX:%d\n", (int)ray_creat_info->ray_end_x / 10);
	// printf("RY:%d\n", (int)ray_creat_info->ray_end_y / 10);
	if (ray_creat_info->ray_end_x < (float)9
		|| ray_creat_info->ray_end_x > (float)(game->map_width * 10 - 10)
		|| ray_creat_info->ray_end_y < (float)9)
	{
		//printf("I am here\n");
		ray_creat_info->ray_length = game->ray_length_max;
		return ;
	}
	else
		ft_loop_for_ft_count_raylen_less_180_more_0(game, ray_creat_info, angle_of_ray);
	return ;
}

void ft_loop_for_ft_count_raylen_less_180_more_0(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray)
{
//printf("CHAR:%c\n", game->map_array[2][8]);
	while(game->map_array[(int)ray_creat_info->ray_end_y / 10][(int)ray_creat_info->ray_end_x / 10] != '1')
	{
// printf("angle_of_ray: %f\n", angle_of_ray);
// printf("RX:%d\n", (int)ray_creat_info->ray_end_x);
// printf("RY:%d\n", (int)ray_creat_info->ray_end_y);
// printf("180\n");
		ray_creat_info->ray_end_y -= (float)10;
		ray_creat_info->distance = game->player_coord_y - ray_creat_info->ray_end_y;
		if(angle_of_ray > DEGREE_90 && angle_of_ray < DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE)
			ray_creat_info->ray_end_x = game->player_coord_x;
		else
			ray_creat_info->ray_end_x = game->player_coord_x + (1 / tan(angle_of_ray)) * ray_creat_info->distance;
		if (ray_creat_info->ray_end_x < (float)9
			|| ray_creat_info->ray_end_x > (float)(game->map_width * 10 - 10)
			|| ray_creat_info->ray_end_y < (float)9)
		{
			//printf("x(%f) y(%f) map(%d)\n", ray_creat_info->ray_end_x, ray_creat_info->ray_end_y, game->map_width * 10 - 10);
			//printf("I am here 180_more_0\n");
			ray_creat_info->ray_length = game->ray_length_max;
			return ;
		}
	}
	return ;
}

void	ft_count_raylen_less_360_more_180(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray)
{
	ray_creat_info->ray_end_y = (int)game->player_coord_y - ray_creat_info->remainder + 10;
	ray_creat_info->distance = ray_creat_info->ray_end_y - game->player_coord_y;
	if(angle_of_ray > DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE	&& angle_of_ray < DEGREE_270)
		ray_creat_info->ray_end_x = game->player_coord_x;
	else
		ray_creat_info->ray_end_x = game->player_coord_x - (1 / tan(angle_of_ray)) * ray_creat_info->distance;
	if (ray_creat_info->ray_end_x < (float)9
		|| ray_creat_info->ray_end_x > (float)(game->map_width * 10 - 10)
		|| ray_creat_info->ray_end_y > (float)(game->map_height * 10 - 10))
	{
		//printf("I am here\n");
		ray_creat_info->ray_length = game->ray_length_max;
		return ;
	}
	ft_loop_for_ft_count_raylen_less_360_more_180(game, ray_creat_info, angle_of_ray);
	return ;
}

void	ft_loop_for_ft_count_raylen_less_360_more_180(t_data	*game, t_ray_creat_info *ray_creat_info, float angle_of_ray)
{
	while(game->map_array[(int)ray_creat_info->ray_end_y / 10][(int)ray_creat_info->ray_end_x / 10] != '1')
	{
		ray_creat_info->ray_end_y += 10;
		ray_creat_info->distance = ray_creat_info->ray_end_y - game->player_coord_y;
		if(angle_of_ray > DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE
			&& angle_of_ray < DEGREE_270)
			ray_creat_info->ray_end_x = game->player_coord_x;
		else
			ray_creat_info->ray_end_x = game->player_coord_x - (1 / tan(angle_of_ray)) * ray_creat_info->distance;
		if (ray_creat_info->ray_end_x < (float)9
			|| ray_creat_info->ray_end_x > (float)(game->map_width * 10 - 10)
			|| ray_creat_info->ray_end_y > (float)(game->map_height * 10 - 10))
		{
			//printf("I am here\n");
			ray_creat_info->ray_length = game->ray_length_max;
			return ;
		}
	}
	return ;
}

void ft_for_ft_create_ray_horizontal(t_data	*game, t_ray_creat_info *ray_creat_info, float *point_of_texture)
{
	if (ray_creat_info->ray_length != game->ray_length_max)
	{
		ray_creat_info->ray_length = sqrt(pow(ray_creat_info->ray_end_x
										- game->player_coord_x, 2)
										+ pow(ray_creat_info->ray_end_y
										- game->player_coord_y, 2));
		*point_of_texture =  fmod(ray_creat_info->ray_end_x,
									(float)10) / (float)10;
		if (*point_of_texture < 0)
			*point_of_texture = -*point_of_texture;
	}
	return ;
}
