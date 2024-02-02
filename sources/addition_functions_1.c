#include "lib_for_cub3D.h"

void	ft_check_is_file_exist(int fd);
void	ft_put_error(char *string);
char	*ft_joined_lines_from_gnl(char *argv[]);
int		ft_y_for_mlxwin_size(char	**splitted_str);

void	ft_put_movement_count(t_data *game)
{
	char	*tmp;

	tmp = ft_itoa(game->movement_count);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->img_of_wall, 0, 0);
	mlx_put_image_to_window (game->mlx, game->mlx_win,
		game->img_of_wall, 40, 0);
	write(1, "STEP:", 5);
	write(1, tmp, ft_strlen(tmp));
	write(1, "\n", 1);
	game->movement_count++;
	mlx_string_put(game->mlx, game->mlx_win, 0, 0, 0x000000, "STEPS:");
	mlx_string_put(game->mlx, game->mlx_win, 80, 0, 0x000000, tmp);
	free(tmp);
	return ;
}

void	ft_check_is_file_exist(int fd)
{
	if (fd == -1)
	{
		ft_put_error("Error: File does not exist");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_put_error(char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		write(STDERR_FILENO, &string[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
	return ;
}

char	*ft_joined_lines_from_gnl(char *argv[])
{
	int		fd;
	char	*line;
	char	*joined_str;
	char	*tmp;

	fd = open(argv[1], O_RDONLY);
	ft_check_is_file_exist(fd);
	joined_str = (char *)malloc(sizeof(char));
	if (!joined_str)
		exit(EXIT_FAILURE);
	joined_str[0] = '\0';
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = joined_str;
		joined_str = ft_strjoin(joined_str, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (joined_str);
}

int	ft_y_for_mlxwin_size(char	**splitted_str)
{
	int	i;

	i = 0;
	while (splitted_str[i] != '\0')
		i++;
	return (i);
}
