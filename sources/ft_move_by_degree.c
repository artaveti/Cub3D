#include "lib_for_cub3D.h"

void	ft_move_by_degree( t_data	*game, float   direction_angle, int one_step, int *player_has_moved)
{
	float	direction_x;
	float	direction_y;
	int 	move_counter;

	direction_x = cos(direction_angle); //x
	direction_y = sin(direction_angle); //y
	move_counter = 0;
	while(game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] != '1' && move_counter < 10)
	{
		printf("Y_FLOAT:%f  X_FLOAT:%f \n", game->player_coord_y, game->player_coord_x);
		printf("Y_INT:%d  X_INT:%d \n", (int)game->player_coord_y, (int)game->player_coord_x);
		printf("Y_INT/10: %d  X_INT/10: %d \n", (int)game->player_coord_y / 10, (int)game->player_coord_x /10);
		printf("Counter\n");
		game->player_coord_x += direction_x;
		game->player_coord_y -= direction_y;
		if (game->splitted_str[(int)game->player_coord_y / 10][(int)game->player_coord_x / 10] == '1')
		{
			game->player_coord_x -= direction_x;
			game->player_coord_y += direction_y;
			break ;
		}
		*player_has_moved = 1;
		move_counter++;
	}
	return ;
}
