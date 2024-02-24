#include "lib_for_cub3D.h"

int	ft_keypress_only_esc(int key, t_data	*game);

int	ft_keypress(int key, t_data *game)
{
	/*if (key == 13 || key == 1 || key == 0 || key == 2)
		ft_action_in_game(key, game);*/
	ft_keypress_only_esc(key, game);
	return (0);
}

int	ft_keypress_only_esc(int key, t_data	*game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		free(game->mlx);
		//system("leaks cub3D");
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	ft_close_with_cross(t_data	*game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	free(game->mlx);
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}
