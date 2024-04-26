/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_for_cub3D.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:27:24 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 19:29:27 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FOR_CUB3D_H
# define LIB_FOR_CUB3D_H

# include <unistd.h> // read(); write();
# include <fcntl.h> // open();
# include <stdlib.h> // malloc(); free(); exit();
# include <stdio.h> // perror();
# include <math.h> // cos(); sin(); tan(); sqrt(); pow(); fmod();
# include <mlx.h>
# include <ctype.h>

# define PI 3.141593
# define DEGREE_0 0 // 0 degree
# define DEGREE_30 0.523599 // PI / 6 // 30.000013 degree
# define DEGREE_45 0.785398 // PI / 4 // 44.999991 degree
# define DEGREE_90 1.570796 //PI / 2 // 89.999981 degree
# define DEGREE_180 PI // 180.00002 degree
# define DEGREE_270 4.712389 // 3 * PI / 2 // 270.000001 degree
# define DEGREE_360 6.283186 //2 * PI //360.00004 degree
# define ONE_DEGREE_TO_RADIAN 0.017453
# define ONE_RADIAN_TO_DEGREE 57.29578
# define ONE_THOUSANDTH_OF_ONE_DEGREE 0.000017
# define SIZE_WIDTH_WINDOW_X 640
# define SIZE_HEIGHT_WINDOW_Y 480
# define FOV_DEGREE 60
# define FOV_RADIAN 1.047198
# define ONE_STEP_FOR_MOVE 5
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define KEY_ESC 53
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define BUFFER_SIZE 1000
# define DELIM " \t\n\v\f\r"

typedef struct attr_count
{
	int	no_count;
	int	so_count;
	int	ea_count;
	int	we_count;
	int	c_count;
	int	f_count;
}	t_count;

typedef struct s_attributes
{
	t_count	count;
	int		attr_count;
	char	*direction_angle;
	char	*so;
	char	*we;
	char	*no;
	char	*ea;
	char	*f;
	char	*c;
}	t_attributes;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_parsing
{
	t_attributes	attr;
	t_player		player;
	char			**map;
	char			*map_first_line;
	int				map_x;
	int				map_y;
	int				height;
	int				attr_line;
	int				width;
}	t_parsing;

typedef struct s_image_info
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

typedef struct s_textures_and_colors_quant
{
	int	flag_north;
	int	flag_south;
	int	flag_west;
	int	flag_east;
	int	flag_floor;
	int	flag_ceiling;
}	t_textures_and_colors_quant;

typedef struct s_data
{
	void						*mlx;
	void						*mlx_win;
	char						*map_str;
	char						**map_splitted_str;
	char						**map_array;
	char						*north_texture;
	char						*south_texture;
	char						*west_texture;
	char						*east_texture;
	char						**floor_color_splitted;
	char						**ceiling_color_splitted;
	unsigned int				floor_color;
	unsigned int				ceiling_color;
	t_textures_and_colors_quant	flags_textures_and_colors_quant;
	int							map_max_width;
	int							map_width;
	int							map_height;
	float						ray_length_max;
	float						player_coord_x;
	float						player_coord_y;
	float						direction_angle;
	float						direction_x;
	float						direction_y;
	float						one_step_in_radian_for_fov;
	t_image_info				*textures;
	t_image_info				image_for_draw;
	t_ray_and_wall				*rays_and_walls;
}	t_data;

typedef struct s_ray_info
{
	float	ray_angle;
	double	ray_to_vertical;
	double	ray_to_horizontal;
	int		wall_side_vertical;
	int		wall_side_horizontal;
	float	point_of_texture_vertical;
	float	point_of_texture_horizontal;
}	t_ray_info;

typedef struct s_ray_creat_info
{
	double	ray_end_x;
	double	ray_end_y;
	double	distance;
	int		remainder;
	double	ray_length;
}	t_ray_creat_info;

typedef struct s_draw_image_info
{
	int		pixel_quant;
	int		wall_side;
	float	step_size;
	float	texture_y;
	float	texture_x;
	int		x;
}	t_draw_image_info;

typedef struct s_move_sliding_info
{
	float	ray_to_vertical;
	float	ray_to_horizontal;
	int		wall_side_vertical;
	int		wall_side_horizontal;
	float	point_of_texture_vertical;
	float	point_of_texture_horizontal;
}	t_move_sliding_info;

//get_next_line
char			*ft_check(char *buf, char *result, int i);
char			*get_next_line(int fd);
//get_next_line_utils
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char *s, int c);
size_t			ft_strlen(char	*s);
char			*ft_free_and_return_null_in_get_next_line(char		*result);
int				ft_assign_result_in_get_next_line(int fd, char		**result,
					int *i);
int				ft_ft_check_in_get_next_line_one(int *buf_index,
					int *bytes_read, int fd, char buf[BUFFER_SIZE + 1]);
char			*ft_ft_check_in_get_next_line_two(char		*result, int i,
					int *buf_index);
char			*ft_ft_check_in_get_next_line_three(char *result, int i,
					int *buf_index);
char			*ft_ft_check_in_get_next_line_four(char *result, int i,
					int *buf_index);
char			*ft_check_in_get_next_line_five(char *result, int i);
void			ft_for_get_next_line(char *result, int *i, char *buf,
					int *buf_index);
//parsing
void			ft_parsing(t_parsing *parsing, int argc, char **argv);
//for parsing
//1
void			free_map(t_parsing *parsing);
void			get_map_size(int fd, t_parsing *parsing);
void			allocate_map_memory(t_parsing *parsing);
void			check_map_size(t_parsing *parsing);
void			ft_get_map(char *argv, t_parsing *parsing);
//2
void			copy_map_lines(int fd, t_parsing *parsing);
void			ft_put_error(char *string);
char			*ft_strdup(char	*s1);
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
int				ft_strncmp(const char	*s1, const char	*s2, size_t	n);
//3
void			ft_check_argc_and_name(int argc, char *argv[]);
void			check_file_exists(char *argv, int *fd);
int				ft_isdigit(int c);
int				simple_atoi(char *str);
int				invalid_color(char *token);
//4
int				ft_for_check_color_one(size_t length, char *color);
int				ft_for_check_color_two(int counter, char *color);
int				check_color_f(char *line);
int				check_color_c(char *line);
void			check_attr_identif(t_parsing *parsing);
//5
void			check_attr_count(t_parsing *parsing);
int				is_attr(char *line);
void			init_attributes(t_parsing *parsing);
void			pars_attributes(t_parsing *parsing, int fd, int *map_start);
void			free_attributes(t_parsing *parsing);
//6
char			*ft_strjoin_n(char *s1, char *s2);
void			join_attribute_path(char **attribute, char *line, int *count);
void			assign_path(t_parsing *parsing, char *type, char *path);
void			ft_for_is_attribute_check_word_count(int word_count, int num);
int				is_attribute(t_parsing *parsing, char *line);
//7
int				is_valid(int row, int col, t_parsing *parsing);
int				is_pl_pos(char c);
void			ft_for_check_borders_one(int	**moves);
void			ft_for_check_borders_two(t_parsing *parsing, int new_ind,
					int new_jind);
void			assign_direct(int **moves);
void			free_arr(int **arr);
//8
int				is_valid_symbol(char c);
int				empty_line(char *line);
int				ft_line_contains_map_data(t_parsing *parsing, int i);
void			ft_for_map_in_the_end_check_assign(int *i, int *prev_map_start);
void			map_in_the_end(t_parsing *parsing);
//9
int				is_space(char c);
void			check_map_sym(t_parsing *parsing);
void			check_player_count(int player_count);
void			fix_player_pos(t_parsing *parsing);
void			inv_sym(char *line);
//10
char			*ft_strpbrk(const char *s, const char *charset);
size_t			ft_strspn(const char *s, const char *accept);
char			*my_strtok(char *s, char *delim);
char			*my_strtok_f(char *s, char *delim);
char			*my_strtok_c(char *s, char *delim);
//11
void			check_borders(t_parsing *parsing, int ind, int jind);
void			ft_for_ft_check_map_check(t_parsing *parsing, int i, int j);
void			ft_check_map(t_parsing *parsing);
int				check_char(char c, const char *charset);
//12
void			*ft_calloc(size_t	count, size_t	size);
void			*ft_memset(void	*b, int c, size_t len);
void			ft_free_line_and_exit(char *line);
//libft.h
char			**ft_split(char const	*s, char c);
void			ft_assign_in_ft_split(size_t *st, size_t *i, size_t *l);
char			*ft_itoa(int n);
//addition
void			ft_put_error(char *string);
void			ft_error_in_malloc_exit(void);
//assign and free
void			ft_assign_null_values_in_struct(t_data	*game);
void			ft_assign_null_values_in_struct_image_info(
					t_image_info *image_info);
void			ft_assign_null_in_struct_flags_textures_and_colors_quant(
					t_data	*game);
void			ft_assign_values_in_struct(t_data *game);
void			ft_free_for_struct(t_data	*game);
void			ft_free_double_pointer_array(char ***array);
void			ft_free_struct_image_info(t_image_info *image_info);
void			ft_malloc_for_rays_walls_textures(t_data *game);
void			ft_mlx_init_mlx_new_window(t_data	*game);
void			ft_free_struct_and_exit(t_data	*game);
//creat map
void			ft_creat_map_str(t_data	*game, char **argv);
void			ft_chech_whitespaces_except_space_in_map(t_data	*game);
void			ft_creat_splitted_map_and_check_only_space_in_line(
					t_data	*game);
void			ft_assign_texture_color_only_map_height_width(t_data	*game);
void			ft_assign_only_map_height_width(t_data	*game, int i);
void			ft_memset_by_one_only_map(t_data	*game, int i);
void			ft_for_ft_memset_by_one_only_map(t_data *game,
					int quant_for_map);
void			ft_assign_only_map(t_data	*game, int i);
void			ft_assign_height_width(t_data	*game);
void			ft_assign_player_coord(t_data	*game);
void			ft_check_texture_and_color_quant(t_data *game);
//direction angle
void			ft_assign_direction_angle(t_data *game, char c);
//creat rays
void			ft_create_rays(t_data	*game);
float			ft_create_ray_vertical(t_data	*game, float angle_of_ray,
					int *wall_side_vertical, float *point_of_texture);
float			ft_create_ray_horizontal(t_data	*game, float angle_of_ray,
					int *wall_side_horizontal, float *point_of_texture);
void			ft_for_ft_create_ray_horizontal(t_data	*game,
					t_ray_creat_info *ray_creat_info, float *point_of_texture);
void			ft_for_ft_create_ray_vertical(t_data	*game,
					t_ray_creat_info *ray_creat_info, float *point_of_texture);
void			ft_assign_ray_creat_info(t_ray_creat_info *ray_creat_info);
//draw image
void			ft_set_images_and_get_info(t_data *game);
void			ft_draw_image(t_data *game);
unsigned int	create_trgb(char *t, char *r, char *g, char *b);
void			my_mlx_pixel_put(t_data *game, int x, int y,
					unsigned int color);
//move
void			ft_move_by_degree( t_data	*game, float direction_angle,
					int one_step, int *player_has_moved);
void			ft_move_for_sliding(t_data	*game, float direction_angle,
					int *player_has_moved);
//exit
int				ft_keypress(int key, t_data *game);
int				ft_close_with_cross(t_data *game);

#endif
