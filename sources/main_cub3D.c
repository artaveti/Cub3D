#include "lib_for_cub3D.h"

int		ft_player_move(int key, t_data	*game);
void	ft_put_pixel_to_window_for_map(t_data *game);
//void	ft_put_pixel_to_window_for_player(t_data *game);
void	ft_put_pixel_to_window_by_size(double x, double y, int color, t_data *game);

int	main(int argc, char *argv[])
{
	t_data	game;

	(void)argc;
	(void)argv;
	//game.xpm_size = 80;
	ft_check_argc_and_name(argc, argv);
	ft_check_map(argv, &game);
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		exit(EXIT_FAILURE);
	game.mlx_win = mlx_new_window(game.mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y,
		"./cub3D");
	if (game.mlx_win == NULL)
		exit(EXIT_FAILURE);


game.px = 160;
game.py = 160;
//game.pa = 0;
game.pdx = cos(game.pa * 5);
game.pdy = sin(game.pa * 5);
printf("angle:%f\npdx:%f\npdy:%f\n\n",game.pa, game.pdx, game.pdy);


int x;
int y;

x = 0;
while(x < SIZE_WIDTH_WINDOW_X)
{
	y = 0;
	while(y < SIZE_HEIGHT_WINDOW_Y)
	{
		mlx_pixel_put(game.mlx, game.mlx_win, x, y, 0xA0A0A0);
		y++;
	}
	x++;
}


ft_put_pixel_to_window_for_map(&game);
//ft_put_pixel_to_window_for_player(&game);
mlx_pixel_put(game.mlx, game.mlx_win, game.px, game.py, 0x00FFFF00); // for player one pixel;
//mlx_pixel_put(game.mlx, game.mlx_win, game.pdx, game.pdy, 0x00FFFF00); // for player one pixel;
//ft_put_pixel_to_window_by_size(game.px, game.py, 0x00FFFF00, &game); // for player;
mlx_key_hook (game.mlx_win, &ft_player_move, &game);

	ft_xpm_file_to_image(&game);
	//game.collectible_count = 0;
	//ft_put_image_to_window(&game);
	//game.movement_count = 0;
	//ft_put_movement_count(&game);
	//mlx_key_hook (game.mlx_win, &ft_keypress, &game);
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	//mlx_loop_hook(game.mlx, &ft_put_animation, &game);
	mlx_loop(game.mlx);
	mlx_destroy_window(game.mlx, game.mlx_win);
	free(game.mlx);
	//system("leaks cub3D");
	exit(EXIT_SUCCESS);
}

int ft_player_move(int key, t_data	*game)
{
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S)
	{	
		printf("px:%f\npy:%f\n\n",game->px, game->py);
		printf("pdx:%f\npdy:%f\n",game->pdx, game->pdy);
		printf("angle:%f\n\n",game->pa);
		mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x000000); // for player one pixel before move;
		//mlx_pixel_put(game->mlx, game->mlx_win, game->pdx, game->pdy, 0x000000); // for direction one pixel before move;
		//ft_put_pixel_to_window_by_size(game->px, game->py, 0x000000, game);
		//mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x000000);

		if (key == KEY_W)
			{ printf("W\n"); game->px += game->pdx; game->py += game->pdy; }
		else if (key == KEY_S)
			{ printf("S\n"); game->px -= game->pdx; game->py -= game->pdy; }
		else if (key == KEY_A)
			{ printf("A\n"); game->pa -= 0.1; if(game->pa <      0) {game->pa += 2 * PI;} game->pdx = cos(game->pa) * 5; game->pdy = sin(game->pa) * 5; }
		else if (key == KEY_D)
			{ printf("D\n"); game->pa += 0.1; if(game->pa > 2 * PI) {game->pa -= 2 * PI;} game->pdx = cos(game->pa) * 5; game->pdy = sin(game->pa) * 5; }
		// if (key == KEY_W)
		// 	game->px -= SIZE_OF_PIXEL;
		// if (key == KEY_S)
		// 	game->px += SIZE_OF_PIXEL;
		// if (key == KEY_A)
		// 	game->py -= SIZE_OF_PIXEL;
		// if (key == KEY_D)
		// 	game->py += SIZE_OF_PIXEL;

		// if (ft_check_is_pixel_map(, game) == 1)
		// {
		// 	ft_put_pixel_to_window_by_size(game->px, game->py, 0x000000, game);
		// 	ft_put_pixel_to_window_by_size(game->px, game->py, 0x000000, game);
		// }
		mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x00FFFF00); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, game->pdx, game->pdy, 0x00FFFF00); // for player one pixel after move;
		//ft_put_pixel_to_window_by_size(game->px, game->py, 0x00FFFF00, game);
	}
	//mlx_clear_window(game->mlx, game->mlx_win);
	//ft_put_pixel_to_window_for_map(game);
	//mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x00FFFF33);
	ft_keypress_only_esc(key, game);
	return (0);
}

void	ft_put_pixel_to_window_for_map(t_data *game)
{

	int	map_x;
	int	map_y;
	int x;
	int y;

	y = 0;
	map_y = 0;
	while (game->splitted_str[map_y] != NULL)
	{
		map_x = 0;
		x = 0;
		while (game->splitted_str[map_y][map_x] != '\0')
		{
			if (game->splitted_str[map_y][map_x] == '1')
				ft_put_pixel_to_window_by_size(x, y, 0x00FFFFFF, game);
			else
				ft_put_pixel_to_window_by_size(x, y, 0x00000000, game);
			x += SIZE_OF_PIXEL;
			map_x++;
		}
		y += SIZE_OF_PIXEL;
		map_y++;
	}
	return ;
}

void	ft_put_pixel_to_window_by_size(double x, double y, int color, t_data *game)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE_OF_PIXEL)
	{
		j = 0;
		while(j < SIZE_OF_PIXEL)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, x + i, y + j, color);
			j++;
		}
		i++;
	}
	return ;
}

void	ft_check_if_pixel_is_map(t_data *game)
{

	int	map_x;
	int	map_y;
	int x;
	int y;

	y = 0;
	map_y = 0;
	while (game->splitted_str[map_y] != NULL)
	{
		map_x = 0;
		x = 0;
		while (game->splitted_str[map_y][map_x] != '\0')
		{
			if (game->splitted_str[map_y][map_x] == '1')
				ft_put_pixel_to_window_by_size(x, y, 0x00FFFFFF, game);
			x += SIZE_OF_PIXEL;
			map_x++;
		}
		y += SIZE_OF_PIXEL;
		map_y++;
	}
	return ;
}
