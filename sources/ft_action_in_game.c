#include "lib_for_cub3D.h"

void	ft_check_is_coord_wall(int key, t_data *game);
void	ft_check_is_coord_collectible(t_data *game);
void	ft_put_string_of_loose(t_data *game);
void	ft_put_string_of_win(t_data *game);

/*void	ft_action_in_game(int key, t_data *game)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_of_background,
		game->player_coord_x * game->xpm_size,
		game->player_coord_y * game->xpm_size);
	if (key == 13)
		game->player_coord_y -= 1;
	else if (key == 1)
		game->player_coord_y += 1;
	else if (key == 0)
		game->player_coord_x -= 1;
	else if (key == 2)
		game->player_coord_x += 1;
	ft_check_is_coord_wall(key, game);
	ft_check_is_coord_collectible(game);
	ft_check_is_coord_exit_red(game);
	ft_check_is_coord_exit_green(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img_of_player,
		game->player_coord_x * game->xpm_size,
		game->player_coord_y * game->xpm_size);
	ft_put_string_of_loose(game);
	ft_put_string_of_win(game);
	return ;
}*/

/*void	ft_check_is_coord_wall(int key, t_data *game)
{
	if (game->splitted_str[game->player_coord_y][game->player_coord_x] == '1')
	{
		if (key == 13)
			game->player_coord_y += 1;
		else if (key == 1)
			game->player_coord_y -= 1;
		else if (key == 0)
			game->player_coord_x += 1;
		else if (key == 2)
			game->player_coord_x -= 1;
		return ;
	}
	else
		ft_put_movement_count(game);
	return ;
}*/

/*void	ft_check_is_coord_collectible(t_data *game)
{
	if (game->splitted_str[game->player_coord_y][game->player_coord_x] == 'C')
	{
		game->splitted_str[game->player_coord_y][game->player_coord_x] = '0';
		game->collectible_count--;
	}
	if (game->collectible_count == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_of_exit_green,
			game->exit_coord_x * game->xpm_size,
			game->exit_coord_y * game->xpm_size);
	return ;
}*/

/*void	ft_put_string_of_loose(t_data *game)
{
	int	x;
	int	y;

	x = game->player_coord_x;
	y = game->player_coord_y;
	if (game->splitted_str[y][x] == 'W')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_of_enemy_1,
			x * game->xpm_size, y * game->xpm_size);
		write(1, "YOU LOSE\n", 9);
		mlx_string_put(game->mlx, game->mlx_win, 160, 30, 0x000000, "YOU LOSE");
		mlx_key_hook (game->mlx_win, &ft_keypress_only_esc, game);
	}
}*/

/*void	ft_put_string_of_win(t_data *game)
{
	int	x;
	int	y;

	x = game->player_coord_x;
	y = game->player_coord_y;
	if (game->splitted_str[y][x] == 'E' && game->collectible_count == 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->img_of_exit_green, x * game->xpm_size,
			y * game->xpm_size);
		write(1, "YOU WIN\n", 8);
		mlx_string_put(game->mlx, game->mlx_win, 160, 30, 0x000000, "YOU WIN");
		mlx_key_hook (game->mlx_win, &ft_keypress_only_esc, game);
	}
	return ;
}*/
