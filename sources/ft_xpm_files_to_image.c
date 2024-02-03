#include "lib_for_cub3D.h"

void	ft_xpm_file_to_image(t_data *game)
{
	int	width;
	int	height;

	// game->img_of_wall = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/wall.xpm", &width, &height);
	// game->img_of_collectible = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/collectible.xpm", &width, &height);
	// game->img_of_exit_red = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/exit_red.xpm", &width, &height);
	// game->img_of_exit_green = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/exit_green.xpm", &width, &height);
	// game->img_of_player = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/player.xpm", &width, &height);
	// game->img_of_background = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/background.xpm", &width, &height);
	// game->img_of_enemy_1 = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/enemy_1.xpm", &width, &height);
	// game->img_of_enemy_2 = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/enemy_2.xpm", &width, &height);
	// game->img_of_enemy_3 = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/enemy_3.xpm", &width, &height);
	// game->img_of_enemy_4 = mlx_xpm_file_to_image(game->mlx,
	// 		"xpm_files/enemy_4.xpm", &width, &height);

	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"png_files/wall.png", &width, &height);
	return ;
}
