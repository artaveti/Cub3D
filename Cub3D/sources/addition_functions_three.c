#include "lib_for_cub3D.h"

void	ft_assign_texture_or_color_N_S_W_E(t_data	*game, char **texture_or_color_splitted);
void	ft_assign_texture_or_color_E_F_C(t_data	*game, char **texture_or_color_splitted);

void	ft_assign_texture_color_only_map_height_width(t_data	*game)
{
		int i;
		char **texture_or_color_splitted;

		texture_or_color_splitted = NULL;
		i = 0;
		while(game->map_splitted_str[i] != NULL)
		{
			texture_or_color_splitted = ft_split(game->map_splitted_str[i], ' ');
			if (texture_or_color_splitted[0] == NULL)
			{
				ft_put_error("Error: Wrong symbol in file");
				exit(EXIT_FAILURE);
			}
			if(texture_or_color_splitted[0][0] == '1')
			{
				ft_free_double_pointer_array(&texture_or_color_splitted);
				break;
			}
			ft_assign_texture_or_color_N_S_W_E(game, texture_or_color_splitted);
			ft_assign_texture_or_color_E_F_C(game, texture_or_color_splitted);
			ft_free_double_pointer_array(&texture_or_color_splitted);
			i++;
		}
		ft_assign_only_map_height_width(game, i);
		return ;
}

void	ft_assign_texture_or_color_N_S_W_E(t_data	*game, char **texture_or_color_splitted)
{
	if(texture_or_color_splitted[0][0] == 'N')
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
	return ;
}

void	ft_assign_texture_or_color_E_F_C(t_data	*game, char **texture_or_color_splitted)
{
	if(texture_or_color_splitted[0][0] == 'F')
	{
		free(game->floor_color_splitted);
		game->floor_color_splitted = ft_split(texture_or_color_splitted[1], ',');
		game->floor_color = create_trgb("0",
								game->floor_color_splitted[0],
								game->floor_color_splitted[1],
								game->floor_color_splitted[2]);
	}
	else if(texture_or_color_splitted[0][0] == 'C')
	{
		free(game->ceiling_color_splitted);
		game->ceiling_color_splitted = ft_split(texture_or_color_splitted[1], ',');
		game->ceiling_color = create_trgb("0",
								game->ceiling_color_splitted[0],
								game->ceiling_color_splitted[1],
								game->ceiling_color_splitted[2]);
	}
	return ;
}

void ft_memset_by_one_only_map(t_data	*game, int i)
{
		int quant_for_map;
		int max_width;
		int len_width;
		int j;

		quant_for_map = 0;
		max_width = 0;
		while(game->map_splitted_str[i] != NULL)
		{
			len_width = ft_strlen(game->map_splitted_str[i]);
			if (len_width > max_width)
				max_width = len_width;
			quant_for_map++;
			i++;
		}
		game->map_array = malloc(sizeof(char *) * (quant_for_map + 1));
		j = 0;
		while(j < quant_for_map)
		{
			game->map_array[j] = malloc(sizeof(char) * (max_width + 1));
			game->map_array[j] = ft_memset(game->map_array[j], '1', max_width);
			game->map_array[j][max_width] = '\0';
			j++;
		}
		game->map_array[j] = NULL;
		return ;
}

void	ft_assign_only_map(t_data	*game, int i)
{
	int x;
	int y;

	y = 0;
	while(game->map_splitted_str[i] != NULL)
	{
		x = 0;
		while(game->map_splitted_str[i][x] != '\0')
		{
			game->map_array[y][x] = game->map_splitted_str[i][x];
			if (game->map_array[y][x] == ' ')
				game->map_array[y][x] = '1';
			x++;
		}
		y++;
		i++;
	}
	return ;
}