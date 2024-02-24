#include "lib_for_cub3D.h"

void	ft_put_image_to_window_coord_count(int y, int x, t_data *game);

/*void	ft_put_image_to_window(t_data *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->splitted_str[++y] != NULL)
	{
		x = -1;
		while (game->splitted_str[y][++x] != '\0')
		{
			if (game->splitted_str[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_of_wall, x * game->xpm_size,
					y * game->xpm_size);
			else if (game->splitted_str[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_of_background, x * game->xpm_size,
					y * game->xpm_size);
			else if (game->splitted_str[y][x] == 'W')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->img_of_enemy_1, x * game->xpm_size,
					y * game->xpm_size);
			ft_put_image_to_window_coord_count(y, x, game);
		}
	}
	return ;
}*/

/*void	ft_put_image_to_window_coord_count(int y, int x, t_data *game)
{
	if (game->splitted_str[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_of_collectible, x * game->xpm_size, y * game->xpm_size);
		game->collectible_count++;
	}
	else if (game->splitted_str[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_of_exit_red, x * game->xpm_size, y * game->xpm_size);
		game->exit_coord_x = x;
		game->exit_coord_y = y;
	}
	else if (game->splitted_str[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_of_player, x * game->xpm_size, y * game->xpm_size);
		game->player_coord_x = x;
		game->player_coord_y = y;
	}
	return ;
}*/