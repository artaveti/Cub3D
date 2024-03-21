#include "lib_for_cub3D.h"

void ft_parsing(t_game	*Game, int argc, char **argv)
{
	ft_check_argc_and_name(argc, argv);
    ft_get_map(argv[1], Game);
    check_attr_count(Game);
    check_attr_identif(Game);
    ft_check_map(Game);
	free_map(Game);
    free_attributes(Game);
	return ;
}

void ft_malloc_for_rays_walls_textures(t_data *game)
{
	game->rays_and_walls = malloc(sizeof(t_ray_and_wall) * SIZE_WIDTH_WINDOW_X);
	if (game->rays_and_walls == NULL)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: in malloc");
		exit(EXIT_FAILURE);
	}
	game->textures = malloc(sizeof(t_image_info) * 4);
	if (game->textures == NULL)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: in malloc");
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_assign_null_values_in_struct_image_info(&(game->textures[0]));
		ft_assign_null_values_in_struct_image_info(&(game->textures[1]));
		ft_assign_null_values_in_struct_image_info(&(game->textures[2]));
		ft_assign_null_values_in_struct_image_info(&(game->textures[3]));
	}
	return ;
}

void ft_mlx_init_mlx_new_window(t_data	*game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: in mlx_init");
		exit(EXIT_FAILURE);
	}
	game->mlx_win = mlx_new_window(game->mlx, SIZE_WIDTH_WINDOW_X,
							SIZE_HEIGHT_WINDOW_Y, "./cub3D");
	if (game->mlx_win == NULL)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: in mlx_new_window");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_check_texture_and_color_quant(t_data *game)
{
	if (game->flags_textures_and_colors_quant.flag_north != 1
		|| game->flags_textures_and_colors_quant.flag_south != 1
		|| game->flags_textures_and_colors_quant.flag_west != 1
		|| game->flags_textures_and_colors_quant.flag_east != 1
		|| game->flags_textures_and_colors_quant.flag_floor != 1
		|| game->flags_textures_and_colors_quant.flag_ceiling != 1)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: ivalid count NO || SO || WE || EA");
		//system("leaks cub3D");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 && *s2 && i < n - 1)
	{
		if ((unsigned char) *s1 == (unsigned char) *s2)
		{
			s1++;
			s2++;
			i++;
		}
		else
			return ((unsigned char) *s1 - (unsigned char) *s2);
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}