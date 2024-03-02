#include "lib_for_cub3D.h"

float ft_create_ray_horizontal(t_data	*game, float angle_of_ray, int *wall_side_horizontal)
{
	float ray_end_x;
	float ray_end_y;
	float distance_y;
	int remainder;
	float ray_length;
	
	ray_end_x = 0;
	ray_end_y = 0;
	//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
	//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00606060); // for ray_end clear;
	remainder = (int)game->player_coord_y % 10;
	if(angle_of_ray > DEGREE_0 && angle_of_ray < DEGREE_180 - ONE_THOUSANDTH_OF_ONE_DEGREE)
	{
		//printf("MORE THAN 0 AND LESS THAN 180\n");
		*wall_side_horizontal = SO;
		ray_end_y = (int)game->player_coord_y - remainder - 1;
		distance_y = game->player_coord_y - ray_end_y;
		if(angle_of_ray > DEGREE_90 && angle_of_ray < DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE)
			ray_end_x = game->player_coord_x;
		else
			ray_end_x = game->player_coord_x + 1 / tan(angle_of_ray) * distance_y;
		if (ray_end_x < (float)10 || ray_end_x > (float)(game->map_width * 10 - 10) || ray_end_y < (float)9)
		{
			//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
			return game->map_height;
		}
		while(game->splitted_str[(int)ray_end_y / 10][(int)ray_end_x / 10] != '1')
		{
			ray_end_y -= 10;
			distance_y = game->player_coord_y - ray_end_y;
			if(angle_of_ray > DEGREE_90 && angle_of_ray < DEGREE_90 + ONE_THOUSANDTH_OF_ONE_DEGREE)
				ray_end_x = game->player_coord_x;
			else
				ray_end_x = game->player_coord_x + 1 / tan(angle_of_ray) * distance_y;
			if (ray_end_x < (float)10 || ray_end_x > (float)(game->map_width * 10 - 10) || ray_end_y < (float)9)
			{
				//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
				return game->map_height;
			}
		}
	}
	else if(angle_of_ray < DEGREE_360 - ONE_THOUSANDTH_OF_ONE_DEGREE
			&& angle_of_ray > DEGREE_180)
	{
		//printf("MORE THAN 180 AND LESS THAN 360\n");
		*wall_side_horizontal = NO;
		ray_end_y = (int)game->player_coord_y - remainder + 10;
		distance_y = ray_end_y - game->player_coord_y;
		if(angle_of_ray > DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE
			&& angle_of_ray < DEGREE_270)
			ray_end_x = game->player_coord_x;
		else
			ray_end_x = game->player_coord_x - 1 / tan(angle_of_ray) * distance_y;
		if (ray_end_x < (float)10 || ray_end_x > (float)(game->map_width * 10 - 10) || ray_end_y > (float)(game->map_height * 10 - 10))
		{
			//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
			return game->map_height;
		}
		while(game->splitted_str[(int)ray_end_y / 10][(int)ray_end_x / 10] != '1')
		{
			ray_end_y += 10;
			distance_y = ray_end_y - game->player_coord_y;
			if(angle_of_ray > DEGREE_270 - ONE_THOUSANDTH_OF_ONE_DEGREE
				&& angle_of_ray < DEGREE_270)
				ray_end_x = game->player_coord_x;
			else
				ray_end_x = game->player_coord_x - 1 / tan(angle_of_ray) * distance_y;
			if (ray_end_x < (float)10 || ray_end_x > (float)(game->map_width * 10 - 10) || ray_end_y > (float)(game->map_height * 10 - 10))
			{
				//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
				return game->map_height;
			}
		}
	}
	else
	{
		*wall_side_horizontal = NO;
		return game->map_height;
	}
	ray_length = sqrt(pow(ray_end_x - game->player_coord_x, 2) + pow(ray_end_y - game->player_coord_y, 2));
	// printf("RAY_END_X: %f  RAY_END_Y: %f\n", ray_end_x, ray_end_yx);
	// printf("RAY_START_X: %f  RAY_START_Y: %f\n", game->player_coord_x, game->player_coord_y);
	// printf("RAY_LENGTH: %f\n", ray_length);
	//mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
	mlx_pixel_put(game->mlx, game->mlx_win, ray_end_x, ray_end_y, 0x00FFFFFF); // for ray_end;
	return ray_length;
}

