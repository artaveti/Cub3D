#include "lib_for_cub3D.h"

//void	my_mlx_pixel_put(t_image_info *image_for_draw, int x, int y, unsigned int color);
void	ft_mlx_pixel_put_middle_x(t_data *game, int x, int y_middle, int y_end, int pixel_quant);
int	ft_assign_start_middle_end_of_x_for_draw(t_data *game, int x, int *y_start, int *y_middle, int *y_end);

void	ft_draw_image(t_data *game)
{
	int x;
	int y_start;
	int y_middle;
	int y_end;
	int						pixel_quant;

	x = 0;
	while(x < SIZE_WIDTH_WINDOW_X)
	{
		pixel_quant = ft_assign_start_middle_end_of_x_for_draw(game, x, &y_start, &y_middle, &y_end);
		while(y_start < y_middle)
		{
			my_mlx_pixel_put(&(game->image_for_draw), x, y_start, 0x003399FF); // must pass Ceiling color 225,30,0
			y_start++;
		}
		ft_mlx_pixel_put_middle_x(game, x, y_middle, y_end, pixel_quant); // must pass Texture color 225,30,0
		while(y_end < SIZE_HEIGHT_WINDOW_Y)
		{
			my_mlx_pixel_put(&(game->image_for_draw), x, y_end, 0x0000CC00); // must pass Floor color 200,100,0
			y_end++;
		}
		x++;
	}
	return ;
}

void	my_mlx_pixel_put(t_image_info *image_for_draw, int x, int y, unsigned int color)
{
	char	*dst;
	//printf("X:[%d] ADDR:[%p] %u\n",x, dst, *(unsigned int*)dst);
	dst = image_for_draw->addr + (y * image_for_draw->line_length + x * (image_for_draw->bits_per_pixel / 8));
	//printf("ADDR BEFORE:[%c]\n", dst[1]);
	*(unsigned int*)dst = color;
	//printf("ADDR AFTER:[%c]\n", dst[1]);
	//printf("X:[%d] ADDR:[%p] %u\n",x, dst, *(unsigned int*)dst);
	return ;
}

void	ft_mlx_pixel_put_middle_x(t_data *game, int x, int y_middle, int y_end, int pixel_quant)
{
	char					*dst;
	//int						pixel_quant;
	unsigned long long		color;
	float					step_size;
	int						wall_side;
	float					texture_y;
	float					texture_x;
	
	//float 	ratio;
	//ratio = (game->rays_and_walls[x].ray_length / game->ray_length_max) * (float)SIZE_HEIGHT_WINDOW_Y;

// //printf("%f\n", game->rays_and_walls[x].ray_length);
		//printf("ray_length:%f\n", game->rays_and_walls[x].ray_length);
	// if (game->rays_and_walls[x].ray_length == 0)
	// {
	// 	pixel_quant = SIZE_HEIGHT_WINDOW_Y;
	// }
	// else if ((int)game->rays_and_walls[x].ray_length >= SIZE_HEIGHT_WINDOW_Y)
	// {
	// 	pixel_quant = 0;
	// }
	// else
		pixel_quant = SIZE_HEIGHT_WINDOW_Y / game->rays_and_walls[x].ray_length;
//printf("%d\n", pixel_quant);
	if (game->rays_and_walls[x].wall_side == NO)
	{
		wall_side = 0;
		//color = 0x00FF9999;
	}
	else if (game->rays_and_walls[x].wall_side == SO)
	{
		wall_side = 1;
		//color = 0x00E5FFCC;
	}
	else if (game->rays_and_walls[x].wall_side == WE)
	{
		wall_side = 2;
		//color = 0x00CCFFFF;
	}
	else
	{
		wall_side = 3;
		//color = 0x00E5CCFF;
	}
//printf("%d\n", wall_side);
	step_size = (float)(game->textures[wall_side].height) / pixel_quant;
//printf("step_size:(%f)\n", step_size);
	if(pixel_quant > 480)
	{
printf("ray_length:%f\n", game->rays_and_walls[x].ray_length);
		//texture_y = (game->textures[wall_side].height - (game->textures[wall_side].height / (pixel_quant / SIZE_HEIGHT_WINDOW_Y))) / 2;
		texture_y = (game->textures[wall_side].height - (game->textures[wall_side].height * game->rays_and_walls[x].ray_length)) / 2;
	}
	else
		texture_y = 0;
	texture_x = game->textures[wall_side].width * game->rays_and_walls[x].point_of_texture;
	//printf("t:(%f) w:(%d) p:(%f)\n", texture_x, game->textures[wall_side].width, game->rays_and_walls[x].point_of_texture);
	//printf("POINT_OF_TEXTURE%f\n", game->rays_and_walls[x].point_of_texture);
	//int pos = (y * size_line + x * (bits_per_pixel / 8)); // from Minilibx site
	while(y_middle < y_end)
	{
		//printf("TEXTURE_X%f\n", texture_x);
		//printf("Y_MIDDLE %d\n", y_middle);
		dst = game->textures[wall_side].addr + ((int)texture_y * game->textures[wall_side].line_length + (int)texture_x * (game->textures[wall_side].bits_per_pixel / 8));
		//printf("DST:[%d] ADDR:[%p] %u\n",y_middle, dst, *(unsigned int*)dst);
		color = *(unsigned int *)dst;
		//printf("COLOR: %u\n", color);
		my_mlx_pixel_put(&(game->image_for_draw), x, y_middle, color); // color
		//printf("TEXTURE_Y %f\n", texture_y);
		texture_y += step_size;
		if (texture_y >= (float)(game->textures[wall_side].height))
		{
			//printf("I am here %d\n", game->textures[wall_side].height);
			texture_y = (float)(game->textures[wall_side].height - 1);
		}
		y_middle++;
	}
	return ;
}

int	ft_assign_start_middle_end_of_x_for_draw(t_data *game, int x, int *y_start, int *y_middle, int *y_end)
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
	//printf("%d\n", pixel_quant);
	*y_start = 0;
	*y_middle = SIZE_HEIGHT_WINDOW_Y / 2 - pixel_quant / 2;
	*y_end = *y_middle + pixel_quant;
	return pixel_quant;
}
