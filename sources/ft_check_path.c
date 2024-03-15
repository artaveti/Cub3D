#include "lib_for_cub3D.h"

/*void	ft_position_coordinates(char **splitted_str, int *x, int *y);
void	flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point cur, char to_fill);
void	ft_check_reach_c_e(char **splitted_str);

void	ft_check_path(char **splitted_str)
{
	int		i;
	t_point	begin;
	t_point	size;

	i = 0;
	ft_position_coordinates(splitted_str, &begin.x, &begin.y);
	size.x = (ft_strlen(splitted_str[0]) - 1);
	while (splitted_str[i] != 0)
		i++;
	size.y = i - 1;
	flood_fill(splitted_str, size, begin);
	ft_check_reach_c_e(splitted_str);
	return ;
}

void	ft_position_coordinates(char **splitted_str, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (splitted_str[i] != '\0')
	{
		j = 0;
		while (splitted_str[i][j] != '\0')
		{
			if (splitted_str[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
	return ;
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'E'
		&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'P'))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
	return ;
}

void	ft_check_reach_c_e(char **splitted_str)
{
	int	i;
	int	j;

	i = -1;
	while (splitted_str[++i] != '\0')
	{
		j = 0;
		while (splitted_str[i][j] != '\0')
		{
			if (splitted_str[i][j] == 'C' || splitted_str[i][j] == 'E'
			|| splitted_str[i][j] == 'P')
			{
				if (splitted_str[i][j + 1] != 'F'
				&& splitted_str[i][j - 1] != 'F'
				&& splitted_str[i + 1][j] != 'F'
				&& splitted_str[i - 1][j] != 'F')
				{
					ft_put_error("Error: Path is not valid");
					exit(EXIT_FAILURE);
				}
			}
			j++;
		}
	}
	return ;
}*/
