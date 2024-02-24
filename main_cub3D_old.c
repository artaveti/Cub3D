#include "lib_for_cub3D.h"

int		ft_player_move(int key, t_data	*game);
void	ft_put_pixel_to_window_for_map(t_data *game);
//void	ft_put_pixel_to_window_for_player(t_data *game);
void	ft_put_pixel_to_window_by_size(double x, double y, int color, t_data *game);
void	ft_draw_rays(t_data *game, int *map);

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


game.mapX = 8, 
game.mapY = 8, 
game.mapS = 64;

// (void)mapX;
// (void)mapY;
// (void)mapS;

int map[] = 
{
1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,1,
1,1,1,1,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,1,
1,1,1,1,1,1,1,1,
};

game.p_map = map;

game.px = 160;
game.py = 160;
game.pa = 0; //PA
game.pdx = cos(game.pa) * 10;
game.pdy = sin(game.pa) * 10;
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
mlx_pixel_put(game.mlx, game.mlx_win, game.pdx + game.px, game.pdy + game.py, 0x00FFFF00); // for player direction one pixel;
//ft_put_pixel_to_window_by_size(game.px, game.py, 0x00FFFF00, &game); // for player;
mlx_key_hook (game.mlx_win, &ft_player_move, &game);

//int a = 1;
//double a = 0.1;
//double b = 0.2;

//printf("++++++++%d\n", mlx_pixel_put(game.mlx, game.mlx_win, a + 0.2, a + b, 0xFFFFFFFF)); // for player one pixel after move;

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
		mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x000000); // for player one pixel before move;
		//mlx_pixel_put(game->mlx, game->mlx_win, game->pdx, game->pdy, 0x000000); // for direction one pixel before move;
		//ft_put_pixel_to_window_by_size(game->px, game->py, 0x000000, game);
		//mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x000000);

		if (key == KEY_W)
			{ printf("W\n"); game->px += game->pdx; game->py += game->pdy; }
		else if (key == KEY_S)
			{ printf("S\n"); game->px -= game->pdx; game->py -= game->pdy; }
		else if (key == KEY_A)
			{ printf("A\n"); game->pa -= 0.1; if(game->pa <      0) {game->pa += 2 * PI;} game->pdx = cos(game->pa) * 10; game->pdy = sin(game->pa) * 10; }
		else if (key == KEY_D)
			{ printf("D\n"); game->pa += 0.1; if(game->pa > 2 * PI) {game->pa -= 2 * PI;} game->pdx = cos(game->pa) * 10; game->pdy = sin(game->pa) * 10; }
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
		printf("px:%f\npy:%f\n\n",game->px, game->py);
		printf("pdx:%f\npdy:%f\n",game->pdx, game->pdy);
		printf("pdx + px:%f\npdy + py:%f\n",game->pdx + game->px, game->pdy + game->py);
		printf("angle:%f\n\n",game->pa);
		mlx_pixel_put(game->mlx, game->mlx_win, game->px, game->py, 0x00FFFF00); // for player one pixel after move;
		mlx_pixel_put(game->mlx, game->mlx_win, game->pdx + game->px, game->pdy + game->py, 0x00FFFF00); // for player one pixel after move;
		//ft_put_pixel_to_window_by_size(game->px, game->py, 0x00FFFF00, game);
		ft_draw_rays(game, game->p_map);
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

void ft_draw_rays(t_data *game, int *map)
{
	int r, mx, my, mp, dof;
	double rx, ry, ra, xo, yo;
	double aTan, nTan;

	ra = game->pa;
	r = 0;
	//mlx_pixel_put(game->mlx, game->mlx_win, game->rx, game->ry, 0x00000000); // for end point of ray;
	while(r < 1)
	{
		
		// Chech Horizontal Lines
		printf("***in ft_draw_rays***\n");
		dof = 0;
		aTan = -1 / tan(ra);
		printf("aTan:%f\n", aTan);
		if (ra > PI) //looking up
		{ ry = (((int)game->py >> 6) << 6) - 0.0001; rx = (game->py - ry) * aTan + game->px; yo = -64; xo = -yo * aTan; }
		if (ra < PI) //looking down
		{ ry = (((int)game->py >> 6) << 6) + 64;     rx = (game->py - ry) * aTan + game->px; yo =  64; xo = -yo * aTan; }
		if(ra == 0 || ra == PI) // looking straight left or right
		{ rx = game->px; ry = game->py; dof = 8; }
		while (dof < 8)
		{
			mx = (int) (rx) >> 6; my = (int)(ry) >> 6; mp = my * game->mapX + mx;
printf("H MP:%d\n", mp);
			if (mp < game->mapX * game->mapY && map[mp] == 1) // hit wall
			{ dof = 8; }
			else // next line
			{ rx += xo; ry += yo; dof += 1; }
			mlx_pixel_put(game->mlx, game->mlx_win, rx, ry, 0x0000CC00); // for end point of ray;
		}
		// Chech Vertical Lines
		dof = 0;
		nTan = -tan(ra);
		if (ra > P2 && ra < P3) //looking left
		{ rx = (((int)game->px >> 6) << 6) - 0.0001; ry = (game->px - rx) * nTan + game->py; xo = -64; yo = -xo * nTan; }
		if (ra < P2 || ra > P3) //looking right
		{ rx = (((int)game->px >> 6) << 6) + 64;     ry = (game->px - rx) * nTan + game->py; xo =  64; yo = -xo * nTan; }
		if(ra == 0 || ra == PI) // looking straight up or down
		{ rx = game->px; ry = game->py; dof = 8; }
		while (dof < 8)
		{
			mx = (int) (rx) >> 6; my = (int)(ry) >> 6; mp = my * game->mapX + mx;
printf("V MP:%d\n", mp);
			if (mp < game->mapX * game->mapY && map[mp] == 1) // hit wall
			{ dof = 8; }
			else // next line
			{ rx += xo; ry += yo; dof += 1; }
			mlx_pixel_put(game->mlx, game->mlx_win, rx, ry, 0x00FF0000); // for end point of ray;
		}
		r++;
	}
	//mlx_pixel_put(game->mlx, game->mlx_win, game->rx, game->ry, 0x0000CC00); // for end point of ray;
	return ;
}









/*void ft_draw_rays(t_data *game, int *map)
{
	int r, mx, my, mp, dof;
	double rx, ry, ra, xo, yo;

	game->ra = game->pa;
	game->r = 0;
	//mlx_pixel_put(game->mlx, game->mlx_win, game->rx, game->ry, 0x00000000); // for end point of ray;
	while(game->r < 1)
	{
		printf("***in ft_draw_rays***\n");
		// Chech Horizontal Lines
		game->dof = 0;
		game->aTan = -1 / tan(game->ra);
		if (game->ra > PI) //looking up
		{ game->ry = (((int)game->py >> 6) << 6) -0.0001; game->rx = (game->py - game->ry) * game->aTan + game->px; game->yo = -64; game->xo = -game->yo * game->aTan; }
		if (game->ra < PI) //looking up
		{ game->ry = (((int)game->py >> 6) << 6) +64;     game->rx = (game->py - game->ry) * game->aTan + game->px; game->yo =  64; game->xo = -game->yo * game->aTan; }
		if(game->ra == 0 || game->ra == PI) // looking straight left or right
		{ game->rx = game->px; game->ry = game->py; game->dof = 8; }
		while (game->dof < 8)
		{
			game->mx = (int) (game->rx) >> 6; game->my = (int)(game->ry) >> 6; game->mp = game->my * game->mapX + game->mx;
			if (game->mp < game->mapX * game->mapY && map[game->mp] == 1) // hit wall
			{ game->dof = 8; }
			else // next line
			{ game->rx += game->xo; game->ry += game->yo; game->dof += 1; }
			mlx_pixel_put(game->mlx, game->mlx_win, game->rx, game->ry, 0x0000CC00); // for end point of ray;
		}

		// Chech Vertical Lines
		game->dof = 0;
		game->nTan = -tan(game->ra);
		if (game->ra > P2 && game->ra < P3) //looking left
		{ game->rx = (((int)game->px >> 6) << 6) - 0.0001; game->ry = (game->px - game->rx) * game->nTan + game->py; game->xo = -64; game->yo = -game->xo * game->nTan; }
		if (game->ra < P2 || game->ra > P3) //looking right
		{ game->rx = (((int)game->px >> 6) << 6) + 64;     game->ry = (game->px - game->rx) * game->nTan + game->py; game->xo =  64; game->yo = -game->xo * game->nTan; }
		if(game->ra == 0 || game->ra == PI) // looking straight up or down
		{ game->rx = game->px; game->ry = game->py; game->dof = 8; }
		while (game->dof < 8)
		{
			game->mx = (int) (game->rx) >> 6; game->my = (int)(game->ry) >> 6; game->mp = game->my * game->mapX + game->mx;
			if (game->mp < game->mapX * game->mapY && map[game->mp] == 1) // hit wall
			{ game->dof = 8; }
			else // next line
			{ game->rx += game->xo; game->ry += game->yo; game->dof += 1; }
			mlx_pixel_put(game->mlx, game->mlx_win, game->rx, game->ry, 0x00FF0000); // for end point of ray;
		}
		game->r++;
	}
	//mlx_pixel_put(game->mlx, game->mlx_win, game->rx, game->ry, 0x0000CC00); // for end point of ray;
}*/