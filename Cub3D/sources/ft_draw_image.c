#include "lib_for_cub3D.h"

void		ft_assign_start_middle_end_of_x_for_draw(t_data *game, int x, int *y_start, int *y_middle, int *y_end);
void		ft_mlx_pixel_put_middle_x(t_data *game, int x, int y_middle, int y_end);
void		ft_for_ft_mlx_pixel_put_middle_x(t_data *game, t_draw_image_info *draw, int y_middle, int y_end);

void	ft_draw_image(t_data *game)
{
	int x;
	int y_start;
	int y_middle;
	int y_end;

	x = 0;
	while(x < SIZE_WIDTH_WINDOW_X)
	{
		ft_assign_start_middle_end_of_x_for_draw(game, x, &y_start, &y_middle, &y_end);
		while(y_start < y_middle)
		{
			my_mlx_pixel_put(game, x, y_start, 0x003399FF); // must pass Ceiling color 225,30,0
			y_start++;
		}
		ft_mlx_pixel_put_middle_x(game, x, y_middle, y_end); // must pass Texture color 225,30,0
		while(y_end < SIZE_HEIGHT_WINDOW_Y)
		{
			my_mlx_pixel_put(game, x, y_end, 0x0000CC00); // must pass Floor color 200,100,0
			y_end++;
		}
		x++;
	}
	return ;
}

void	my_mlx_pixel_put(t_data *game, int x, int y, unsigned int color)
{
	char	*dst;
	
	if (x >= SIZE_WIDTH_WINDOW_X || y >= SIZE_HEIGHT_WINDOW_Y)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: in my_mlx_pixel_put");
		exit(EXIT_FAILURE);
	}
	dst = game->image_for_draw.addr + (y * game->image_for_draw.line_length + x * (game->image_for_draw.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return ;
}

void	ft_assign_start_middle_end_of_x_for_draw(t_data *game, int x, int *y_start, int *y_middle, int *y_end)
{
	int pixel_quant;

	if ((int)game->rays_and_walls[x].ray_length == 0)
	{
		pixel_quant = SIZE_HEIGHT_WINDOW_Y;
	}
	else if ((int)game->rays_and_walls[x].ray_length >= SIZE_HEIGHT_WINDOW_Y)
	{
		pixel_quant = 0;
	}
	else
		pixel_quant = SIZE_HEIGHT_WINDOW_Y / game->rays_and_walls[x].ray_length;
	*y_start = 0;
	*y_middle = SIZE_HEIGHT_WINDOW_Y / 2 - pixel_quant / 2;
	*y_end = *y_middle + pixel_quant;
	return ;
}

void	ft_mlx_pixel_put_middle_x(t_data *game, int x, int y_middle, int y_end)
{
	t_draw_image_info draw;

	draw.x = x;
	draw.pixel_quant = SIZE_HEIGHT_WINDOW_Y
						/ game->rays_and_walls[x].ray_length;
	draw.wall_side = game->rays_and_walls[x].wall_side;
	draw.step_size = (float)(game->textures[draw.wall_side].height)
						/ draw.pixel_quant;
	if(draw.pixel_quant > SIZE_HEIGHT_WINDOW_Y)
		draw.texture_y = (game->textures[draw.wall_side].height -
					(game->textures[draw.wall_side].height
					* game->rays_and_walls[x].ray_length)) / 2;
	else
		draw.texture_y = 0;
	draw.texture_x = game->textures[draw.wall_side].width
				* game->rays_and_walls[x].point_of_texture;
	if (draw.texture_x >= game->textures[draw.wall_side].width
		|| draw.texture_y >= game->textures[draw.wall_side].height)
	{
		ft_free_for_struct(game);
		ft_put_error("Error: in ft_mlx_pixel_put_middle_x");
		exit(EXIT_FAILURE);
	}
	ft_for_ft_mlx_pixel_put_middle_x(game, &draw, y_middle, y_end);
	return ;
}

void ft_for_ft_mlx_pixel_put_middle_x(t_data *game, t_draw_image_info *draw, int y_middle, int y_end)
{
	char					*dst;
	unsigned long long		color;

	while(y_middle < y_end)
	{
		dst = game->textures[draw->wall_side].addr + ((int)(draw->texture_y)
				* game->textures[draw->wall_side].line_length
				+ (int)(draw->texture_x)
				* (game->textures[draw->wall_side].bits_per_pixel / 8));
		color = *(unsigned int *)dst;
		my_mlx_pixel_put(game, draw->x, y_middle, color);
		draw->texture_y += draw->step_size;
		if (draw->texture_y >= (float)(game->textures[draw->wall_side].height))
			draw->texture_y = (float)(game->textures[draw->wall_side].height
								- 1);
		y_middle++;
	}
	return ;
}
