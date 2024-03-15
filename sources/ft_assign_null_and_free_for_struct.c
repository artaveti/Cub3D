#include "lib_for_cub3D.h"

void ft_assign_null_values_in_struct(t_data	*game)
{
	game->mlx = NULL;
	game->mlx_win = NULL;
	game->joined_str = NULL;
	game->splitted_str_1 = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->ray_length_max = 0;
	game->player_coord_x = 0;
	game->player_coord_y = 0;
	game->direction_angle = 0;
	game->direction_x = 0;
	game->direction_y = 0;
	game->textures = NULL;
	ft_assign_null_values_in_struct_image_info(&(game->image_for_draw));
	game->rays_and_walls = NULL;
	game->xpm_size = 0;
	game->img_wall = NULL;
	game->splitted_str = NULL;
	return ;
}

void ft_assign_null_values_in_struct_image_info(t_image_info *image_info)
{
	image_info->img = NULL;
	image_info->addr = NULL;
	image_info->bits_per_pixel = 0;
	image_info->line_length = 0;
	image_info->endian = 0;
	image_info->width = 0;
	image_info->height = 0;
	return ;
}

void	ft_free_for_struct(t_data	*game)
{
	free(game->mlx);
	free(game->mlx_win);
	free(game->joined_str);
	ft_free_double_pointer_array(&(game->splitted_str_1));
	if (game->textures != NULL)
	{
		ft_free_struct_image_info(&(game->textures[0]));
		ft_free_struct_image_info(&(game->textures[1]));
		ft_free_struct_image_info(&(game->textures[2]));
		ft_free_struct_image_info(&(game->textures[3]));
		free(game->textures);
	}
	free(game->image_for_draw.img);
	free(game->image_for_draw.addr);
	free(game->rays_and_walls);
	game->xpm_size = 0;
	free(game->img_wall);
	ft_free_double_pointer_array(&(game->splitted_str));
	return ;
}

void	ft_free_double_pointer_array(char ***array)
{
	int		i;
	char	**tmp;

	if (!*array || *array == NULL)
		return ;
	tmp = *array;
	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(*array);
	*array = NULL;
	return ;
}

void	ft_free_struct_image_info(t_image_info *image_info)
{
	free(image_info->img);
	image_info->img = NULL;
	free(image_info->addr);
	image_info->addr = NULL;
	return ;
}
