#include "lib_for_cub3D.h"

// if (SIZE_HEIGHT_WINDOW_Y == 0 || SIZE_WIDTH_WINDOW_X == 0) free, exit;
// map size check ???
// problem whem map more than 10x10 

void	ft_assign_texture_and_color(t_data	*game, char **splitted_str);

int	main(int argc, char **argv)
{
	t_game	Game;
	t_data	game;

(void)argc;
(void)argv;
	// ft_check_argc_and_name(argc, argv);
    // ft_get_map(argv[1], &Game);
    // check_attr_count(&Game);
    // check_attr_identif(&Game);
    // ft_check_map(&Game);
	// free_map(&Game);
    // free_attributes(&Game);

	ft_assign_null_values_in_struct(&game);
	game.rays_and_walls = malloc(sizeof(t_ray_and_wall) * SIZE_WIDTH_WINDOW_X);
	if (game.rays_and_walls == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_put_error("Error: in malloc");
		exit(EXIT_FAILURE);
	}
	game.textures = malloc(sizeof(t_image_info) * 4);
	if (game.textures == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_free_for_struct(&game);
		ft_put_error("Error: in malloc");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_assign_null_values_in_struct_image_info(&(game.textures[0]));
		ft_assign_null_values_in_struct_image_info(&(game.textures[1]));
		ft_assign_null_values_in_struct_image_info(&(game.textures[2]));
		ft_assign_null_values_in_struct_image_info(&(game.textures[3]));
	}
	game.mlx = mlx_init();
	if (game.mlx == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_free_for_struct(&game);
		ft_put_error("Error: in mlx_init");
		exit(EXIT_FAILURE);
	}
	game.mlx_win = mlx_new_window(game.mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y, "./cub3D");
	if (game.mlx_win == NULL)
	{
		free_map(&Game);
    	free_attributes(&Game);
		ft_free_for_struct(&game);
		ft_put_error("Error: in mlx_new_window");
		exit(EXIT_FAILURE);
	}

	char *c;
	int read_result;
	int quant_for_malloc;
	int fd_map;
	char **splitted_str;

	c = ft_strdup(" ");
	read_result = 1;
	quant_for_malloc = 0;
	fd_map = open(argv[1], O_RDONLY);
	while(read_result > 0)
	{
		read_result = read(fd_map, c, 1);
		if (read_result > 0)
			//printf("C:(%s)\n", c);
		quant_for_malloc++;
		//printf("I:(%d)\n", i);
	}
	printf("QUANT:(%d)\n", quant_for_malloc);
	close(fd_map);
	free(c);
	fd_map = open(argv[1], O_RDONLY);
	c = malloc(sizeof(char) * quant_for_malloc + 1);
	read(fd_map, c, quant_for_malloc);
	c[quant_for_malloc] = '\0';
	printf("STR_LEN:(%zu)\n", ft_strlen(c));
	printf("STR:(%s)\n", c);
	int q;
	q = 0;
	while(c[q] != '\0')
	{
		if(c[q] == '\t' || c[q] == '\v' || c[q] == '\f' || c[q] == '\r')
		{
			ft_put_error("Error: Wrong symbol in file");
			exit(EXIT_FAILURE);
		}
		q++;
	}
	splitted_str = ft_split(c, '\n');

	int p;
	int r;
	int flag_whitespaces;

	p = 0;
	while(splitted_str[p] != NULL)
	{
		r = 0;
		flag_whitespaces = 0;
		while(splitted_str[p][r] != '\0')
		{
			if(splitted_str[p][r] != ' ')
			{
				flag_whitespaces = 1;
			}
			r++;
		}
		if(flag_whitespaces == 0)
		{
			ft_put_error("Error: Wrong symbol in file");
			exit(EXIT_FAILURE);
		}
		printf("SPLITTED_STR:[%d](%s)\n",p, splitted_str[p]);
		p++;
	}
	ft_assign_texture_and_color(&game, splitted_str);
	//printf("C:(%s)\n", game.floor_color);
	int m;
	m = 0;
	while(game.map_array[m] != NULL)
	{
		printf("MAP:[%d](%s)\n", m, game.map_array[m]);
		m++;
	}
	printf("H:(%d), W(%d)\n", game.map_height, game.map_width);


 	ft_set_images_and_get_info(&game, &Game);
	system("leaks cub3D");
printf("X:%d Y:%d W:%d H:%d\n",Game.player.x, Game.player.y, Game.width, Game.height);
	// game.map_width = Game.width - 1;
	// game.map_height = Game.height;
	// game.map_array = Game.map;
	game.ray_length_max = 10000;//(float)sqrt(pow(game.map_width - 2, 2) + pow(game.map_height - 2, 2)) * 10;
	printf("game.ray_length_max: %f\n", game.ray_length_max);
	// game.player_coord_x = Game.player.x * 10 + 5; // * 10 + 5
	// game.player_coord_y = Game.player.y * 10 + 5; // * 10 + 5
	//ft_assign_direction_angle(&game, &Game);
	game.direction_angle = DEGREE_90;
	game.direction_x = cos(game.direction_angle); //x
	game.direction_y = sin(game.direction_angle); //y
	ft_create_rays(&game); // draw first picture
	ft_draw_image(&game); // draw first picture
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.image_for_draw.img, 0, 0); // draw first picture
	mlx_key_hook (game.mlx_win, &ft_keypress, &game); // player move
	mlx_hook(game.mlx_win, 17, 0, &ft_close_with_cross, &game);
	mlx_loop(game.mlx);
	ft_free_for_struct(&game);

	exit(EXIT_SUCCESS);
}



void	ft_assign_texture_and_color(t_data	*game, char **splitted_str)
{
		(void)game;
		int i;
		int j;
		char **texture_or_color_splitted;

		texture_or_color_splitted = NULL;
		i = 0;
		while(splitted_str[i] != NULL)
		{
			texture_or_color_splitted = ft_split(splitted_str[i], ' ');
			if (texture_or_color_splitted[0] == NULL)
			{
				ft_put_error("Error: Wrong symbol in file");
				exit(EXIT_FAILURE);
			}
			if(texture_or_color_splitted[0][0] == '1')
				break;
			else if(texture_or_color_splitted[0][0] == 'N')
			{
				free(game->north_texture);
				game->north_texture = ft_strdup(texture_or_color_splitted[1]);
			}
			else if(texture_or_color_splitted[0][0] == 'S')
			{
				free(game->south_texture);
				game->south_texture = ft_strdup(texture_or_color_splitted[1]);
			}
			else if(texture_or_color_splitted[0][0] == 'W')
			{
				free(game->west_texture);
				game->west_texture = ft_strdup(texture_or_color_splitted[1]);
			}
			else if(texture_or_color_splitted[0][0] == 'E')
			{
				free(game->east_texture);
				game->east_texture = ft_strdup(texture_or_color_splitted[1]);
			}
			else if(texture_or_color_splitted[0][0] == 'F')
			{
				free(game->floor_color);
				game->floor_color = ft_strdup(texture_or_color_splitted[1]);
			}
			else if(texture_or_color_splitted[0][0] == 'C')
			{
				free(game->ceiling_color);
				game->ceiling_color = ft_strdup(texture_or_color_splitted[1]);
			}

int p;
p = 0;
while(texture_or_color_splitted[p] != NULL)
{
	printf("texture_or_color_splitted:[%d](%s)\n",p, texture_or_color_splitted[p]);
	p++;
}

			ft_free_double_pointer_array(&texture_or_color_splitted);
			i++;
		}
		int quant_for_map;
		int i_for_map;
		int max_width;
		int len_width;
		int position;

		max_width = 0;
		i_for_map = i;
		quant_for_map = 0;
		while(splitted_str[i] != NULL)
		{
			j = 0;
			while(splitted_str[i][j] != '\0')
			{
				if(splitted_str[i][j] == ' ')
					splitted_str[i][j] = '1';
				j++;
			}
			quant_for_map++;
			i++;
		}
		game->map_array = malloc(sizeof(char *) * (quant_for_map + 1));
		j = 0;
		while(splitted_str[i_for_map] != NULL)
		{
			game->map_array[j] = ft_strdup(splitted_str[i_for_map]);
			len_width = ft_strlen(game->map_array[j]);
			position = 0;
			while(game->map_array[j][position] != '\0')
			{
				if(game->map_array[j][position] == 'N'
					|| game->map_array[j][position] == 'S'
					|| game->map_array[j][position] == 'W'
					|| game->map_array[j][position] == 'E')
					{
						game->player_coord_x = position * 10 + 5;
						game->player_coord_y = j * 10 + 5;
						break ;
					}
				position++;
			}
			if (len_width > max_width)
			{
				max_width = len_width;
			}
			j++;
			i_for_map++;
		}
		game->map_array[j] = NULL;
		game->map_height = quant_for_map;
		game->map_width = max_width;
		printf("QUANT_FOR_MAP: %d\n", quant_for_map);
		return ;
}
