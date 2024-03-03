#include "lib_for_cub3D.h"

int	ft_close_with_cross(t_data	*game)
{
	//mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}
