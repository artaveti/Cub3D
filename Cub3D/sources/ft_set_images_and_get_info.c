#include "lib_for_cub3D.h"

void	ft_check_in_set_images_and_get_info(t_data *game, void *img_or_addr);
void	ft_get_data_addr(t_data *game);

void	ft_set_images_and_get_info(t_data *game)
{
	game->image_for_draw.img = mlx_new_image(game->mlx, SIZE_WIDTH_WINDOW_X, SIZE_HEIGHT_WINDOW_Y); // empty image
	ft_check_in_set_images_and_get_info(game, game->image_for_draw.img);
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx, game->north_texture,
							&(game->textures[0].width), &(game->textures[0].height)); // NO
	ft_check_in_set_images_and_get_info(game, game->textures[0].img);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx, game->south_texture,
							&(game->textures[1].width), &(game->textures[1].height)); // SO
	ft_check_in_set_images_and_get_info(game, game->textures[1].img);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx, game->west_texture,
							&(game->textures[2].width), &(game->textures[2].height)); // WE
	ft_check_in_set_images_and_get_info(game, game->textures[2].img);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx, game->east_texture,
							&(game->textures[3].width), &(game->textures[3].height)); // EA
	ft_check_in_set_images_and_get_info(game, game->textures[3].img);
	ft_get_data_addr(game);
	return ;
}

void ft_check_in_set_images_and_get_info(t_data *game, void *img_or_addr)
{
	if (img_or_addr == NULL)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: Wrong xpm file");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_get_data_addr(t_data *game)
{
	game->image_for_draw.addr = mlx_get_data_addr(game->image_for_draw.img,
								&(game->image_for_draw.bits_per_pixel),
								&(game->image_for_draw.line_length),
								&(game->image_for_draw.endian)); // empty image
	ft_check_in_set_images_and_get_info(game, game->image_for_draw.addr);
	game->textures[0].addr = mlx_get_data_addr(game->textures[0].img,
								&(game->textures[0].bits_per_pixel),
								&(game->textures[0].line_length),
								&(game->textures[0].endian)); // NO
	ft_check_in_set_images_and_get_info(game, game->textures[0].addr);
	game->textures[1].addr = mlx_get_data_addr(game->textures[1].img,
								&(game->textures[1].bits_per_pixel),
								&(game->textures[1].line_length),
								&(game->textures[1].endian)); // SO
	ft_check_in_set_images_and_get_info(game, game->textures[1].addr);
	game->textures[2].addr = mlx_get_data_addr(game->textures[2].img,
								&(game->textures[2].bits_per_pixel),
								&(game->textures[2].line_length),
								&(game->textures[2].endian)); // WE
	ft_check_in_set_images_and_get_info(game, game->textures[2].addr);
	game->textures[3].addr = mlx_get_data_addr(game->textures[3].img,
								&(game->textures[3].bits_per_pixel),
								&(game->textures[3].line_length),
								&(game->textures[3].endian)); // EA
	ft_check_in_set_images_and_get_info(game, game->textures[3].addr);
	return ;
}
