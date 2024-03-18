#include "lib_for_cub3D.h"

void ft_assign_ray_creat_info(t_ray_creat_info *ray_creat_info)
{
	ray_creat_info->ray_length = 0;
	ray_creat_info->ray_end_x = 0;
	ray_creat_info->ray_end_y = 0;
	return ;
}

void	ft_assign_direction_angle(t_data *game, t_game *Game)// NO, SO, WE, EA
{
	if(Game->attr.direction_angle[0] == 'N')
		game->direction_angle = DEGREE_90;
	else if(Game->attr.direction_angle[0] == 'S')
		game->direction_angle = DEGREE_270;
	else if(Game->attr.direction_angle[0] == 'W')
		game->direction_angle = DEGREE_180;
	else if(Game->attr.direction_angle[0] == 'E')
		game->direction_angle = DEGREE_0;
	return ;
}

int	ft_close_with_cross(t_data	*game)
{
	ft_free_for_struct(game);
	exit(EXIT_SUCCESS);
}
