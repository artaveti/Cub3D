#ifndef LIB_FOR_CUB3D
# define LIB_FOR_CUB3D

# include <unistd.h> // read(); write();
# include <fcntl.h> // open();
# include <stdlib.h> // malloc(); free(); exit();
# include <stdio.h> // perror();
# include <math.h>
# include <mlx.h>

# define PI 3.1415926535
# define P2 PI/2
# define P3 3*PI/2
# define SIZE_WIDTH_WINDOW_X 640
# define SIZE_HEIGHT_WINDOW_Y 320  //480
# define SIZE_OF_PIXEL 40
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define BUFFER_SIZE_FOR_GNL 100

typedef struct s_point
{
	int			x;
	int			y;
}	t_point;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	*joined_str;
	char	**splitted_str_1;
	int		xpm_size;


int mapX;
int mapY;
int mapS;
int *p_map;

double px;
double py;
double pdx;
double pdy;
double pa;

int r;
int mx;
int my;
int mp;
int dof;

double rx;
double ry;
double ra;
double xo;
double yo;
double aTan;
double nTan;
	//int		x_of_window;
	//int		y_of_window;
	void	*img_of_wall;
	void	*img_of_collectible;
	void	*img_of_exit_red;
	void	*img_of_exit_green;
	void	*img_of_player;
	void	*img_of_background;
	void	*img_of_enemy_1;
	void	*img_of_enemy_2;
	void	*img_of_enemy_3;
	void	*img_of_enemy_4;
	void 	*img_wall;
	char	**splitted_str;
	int		player_coord_x;
	int		player_coord_y;
	int		exit_coord_x;
	int		exit_coord_y;
	int		collectible_count;
	int		movement_count;
}	t_data;

//check
void	ft_check_argc_and_name(int argc, char *argv[]);
void	ft_check_map(char *argv[], t_data *game);
void	ft_check_characters(char **splitted_str);
void	ft_check_path(char **splitted_str);
//mlx
void	ft_xpm_file_to_image(t_data *game);
void	ft_put_image_to_window(t_data *game);
void	ft_action_in_game(int key, t_data *game);
void	ft_check_is_coord_exit_red(t_data *game);
void	ft_check_is_coord_exit_green(t_data *game);
int		ft_put_animation(t_data *game);
//libft.h
size_t	ft_strlen(const	char *s);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	**ft_split(char const	*s, char c);
char	*ft_itoa(int n);
//get_next_line
char	*get_next_line(int fd);
char	*ft_gstrchr(char	*s, int c);
size_t	ft_gstrlen(char	*s);
//addition1
char	*ft_joined_lines_from_gnl(char *argv[]);
void	ft_put_error(char *string);
//int		ft_y_for_mlxwin_size(char **splitted_str);
void	ft_put_movement_count(t_data *game);
//addition2
int		ft_keypress_only_esc(int key, t_data *game);
int		ft_keypress(int key, t_data *game);
int		ft_close_with_cross(t_data *game);

#endif