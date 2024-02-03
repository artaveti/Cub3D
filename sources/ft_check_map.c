#include "lib_for_cub3D.h"

void	ft_check_joined_splitted(char *joined_str, char **splitted_str);
void	ft_check_extra_line(char *joined);
void	ft_check_line_length(char **splitted_str);
void	ft_check_quantity_of_c_e_p(char *joined_str);

void	ft_check_map(char *argv[], t_data *game)
{
	game->joined_str = ft_joined_lines_from_gnl(argv);
	game->splitted_str_1 = ft_split(game->joined_str, '\n');
	ft_check_joined_splitted(game->joined_str, game->splitted_str_1);
	ft_check_extra_line(game->joined_str);
	ft_check_line_length(game->splitted_str_1);
	ft_check_characters(game->splitted_str_1);
	ft_check_quantity_of_c_e_p(game->joined_str);
	ft_check_path(game->splitted_str_1);
	game->splitted_str = ft_split(game->joined_str, '\n');
	//game->x_of_window = ft_strlen(game->splitted_str_1[0]);
	//game->y_of_window = ft_y_for_mlxwin_size(game->splitted_str_1);
	return ;
}

void	ft_check_joined_splitted(char *joined_str, char **splitted_str)
{
	int		i;
	size_t	n;

	i = 0;
	n = 0;
	while (joined_str[i] != '\0')
	{
		if (joined_str[i] == '\n')
			n++;
		i++;
	}
	if (joined_str[0] == '\0' || ft_strlen(joined_str) == n
		|| splitted_str[1] == NULL || splitted_str[2] == NULL)
	{
		ft_put_error("Error: Wrong map");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_check_extra_line(char *joined)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(joined);
	while (joined[n - 1] == '\n')
		n--;
	while (joined[i] == '\n')
		i++;
	while (i < n)
	{
		if (joined[i] == '\n' && joined[i + 1] == '\n')
		{
			ft_put_error("Error: Extra New Line in map");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	ft_check_line_length(char **splitted_str)
{
	int	i;
	int	first_line_length;
	int	current_line_length;

	first_line_length = ft_strlen(splitted_str[0]);
	i = 1;
	while (splitted_str[i] != NULL)
	{
		current_line_length = ft_strlen(splitted_str[i]);
		if (first_line_length != current_line_length)
		{
			ft_put_error("Error: Wrong line length in map");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	ft_check_quantity_of_c_e_p(char *joined_str)
{
	int	i;
	int	c;
	int	e;
	int	p;

	i = 0;
	c = 0;
	e = 0;
	p = 0;
	while (joined_str[i] != '\0')
	{
		if (joined_str[i] == 'C')
			c++;
		if (joined_str[i] == 'E')
			e++;
		if (joined_str[i] == 'P')
			p++;
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
	{
		ft_put_error("Error: Wrong quantity of C_E_P");
		exit(EXIT_FAILURE);
	}
	return ;
}
