#ifndef LIB_FOR_CUB3D
# define LIB_FOR_CUB3D

# include <unistd.h> // read(); write();
# include <fcntl.h> // open();
# include <stdlib.h> // malloc(); free(); exit();
# include <stdio.h> // perror();
# include <math.h> // cos(); sin(); tan(); sqrt(); pow(); fmod();
# include <mlx.h>

# define PI 3.141593
# define DEGREE_0 0 // 0 degree
# define DEGREE_30 PI / 6 // 30.000013 degree
# define DEGREE_45 PI / 4 // 44.999991 degree
# define DEGREE_90 PI / 2 // 89.999981 degree
# define DEGREE_180 PI // 180.00002 degree
# define DEGREE_270 3 * PI / 2 // 270.000001 degree
# define DEGREE_360 2 * PI //360.00004 degree
# define ONE_DEGREE_TO_RADIAN 0.017453
# define ONE_RADIAN_TO_DEGREE 57.29578
# define ONE_THOUSANDTH_OF_ONE_DEGREE 0.000017
# define SIZE_WIDTH_WINDOW_X 640
# define SIZE_HEIGHT_WINDOW_Y 480
# define FOV_DEGREE 60
# define FOV_RADIAN 1.047198
# define ONE_STEP_IN_RADIAN_FOR_FOV FOV_RADIAN / SIZE_WIDTH_WINDOW_X
# define ONE_STEP_FOR_MOVE 3
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_ESC 53
# define NO 10
# define SO 20
# define WE 30
# define EA 40
# define BUFFER_SIZE_FOR_GNL 100

typedef struct	s_image_info
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image_info;

typedef struct s_ray_and_wall
{
	float	ray_length;
	int		wall_side;
	float	point_of_texture;
}	t_ray_and_wall;

typedef struct s_data
{
	int  	f;
	void	*mlx;
	void	*mlx_win;
	char	*joined_str;
	char	**splitted_str_1;
	char	**splitted_str;
	int 	map_width;
	int		map_height;
	float 	ray_length_max;
	float	player_coord_x;
	float	player_coord_y;
	float   direction_angle;
	float	direction_x;
	float	direction_y;
	t_image_info 		*textures;
	t_image_info 		image_for_draw;
	t_ray_and_wall		*rays_and_walls;
}	t_data;

typedef struct s_ray_info
{
	float ray_angle;
	float ray_to_vertical;
	float ray_to_horizontal;
	int wall_side_vertical;
	int wall_side_horizontal;
	float point_of_texture_vertical;
	float point_of_texture_horizontal;
}	t_ray_info;

typedef struct s_ray_creat_info
{
	float ray_end_x;
	float ray_end_y;
	float distance;
	int remainder;
	float ray_length;
}	t_ray_creat_info;

//libft.h
size_t	ft_strlen(const	char *s);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	**ft_split(char const	*s, char c);
char	*ft_itoa(int n);
//check
void	ft_check_argc_and_name(int argc, char *argv[]);
void	ft_check_map(char *argv[], t_data *game);
void	ft_check_characters(char **splitted_str);
void	ft_check_path(char **splitted_str);
//get_next_line
char	*get_next_line(int fd);
char	*ft_gstrchr(char	*s, int c);
size_t	ft_gstrlen(char	*s);
//addition1
char	*ft_joined_lines_from_gnl(char *argv[]);
void	ft_put_error(char *string);
//int		ft_y_for_mlxwin_size(char **splitted_str);
//void		ft_put_movement_count(t_data *game);

void	ft_assign_null_values_in_struct(t_data	*game);
void	ft_assign_null_values_in_struct_image_info(t_image_info *image_info);
void	ft_free_for_struct(t_data	*game);
void	ft_free_double_pointer_array(char ***array);
void	ft_free_struct_image_info(t_image_info *image_info);
void	ft_set_images_and_get_info(t_data *game);
void	ft_draw_image(t_data *game);
void	my_mlx_pixel_put(t_data *game, int x, int y, unsigned int color);
int		ft_keypress(int key, t_data *game);
int		ft_keypress_only_esc(int key, t_data *game);
int		ft_close_with_cross(t_data *game);
void	ft_change_player_coord(int key, t_data	*game);
void	ft_change_direction_angle(int key, t_data	*game);
void	ft_move_by_degree( t_data	*game, float	direction_angle, int one_step, int *player_has_moved);
void	ft_move_for_sliding(t_data	*game, float   direction_angle, int *player_has_moved);
void 	ft_create_rays(t_data	*game);
float 	ft_create_ray_vertical(t_data	*game, float angle_of_ray, int *wall_side_vertical, float *point_of_texture);
float 	ft_create_ray_horizontal(t_data	*game, float angle_of_ray, int *wall_side_horizontal, float *point_of_texture);

#endif
