#include "lib_for_cub3D.h"

void	ft_put_image_to_animation(int i, int y, int x, t_data *game)
{
	if (game->splitted_str[y][x] == 'W')
	{
		if (i < 10)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->img_of_enemy_1, x * game->xpm_size,
				y * game->xpm_size);
		else if (i > 10 && i < 30)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->img_of_enemy_2, x * game->xpm_size,
				y * game->xpm_size);
		else if (i > 20 && i < 40)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->img_of_enemy_3, x * game->xpm_size,
				y * game->xpm_size);
		else if (i > 30 && i < 50)
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->img_of_enemy_4, x * game->xpm_size,
				y * game->xpm_size);
	}
	return ;
}

int	ft_put_animation(t_data *game)
{
	static int	i;
	int			y;
	int			x;

	if (i > 50)
		i = 0;
	y = 0;
	while (game->splitted_str[y] != NULL)
	{
		x = 0;
		while (game->splitted_str[y][x] != '\0')
		{
			ft_put_image_to_animation(i, y, x, game);
			x++;
		}
		y++;
	}	
	i++;
	return (0);
}
