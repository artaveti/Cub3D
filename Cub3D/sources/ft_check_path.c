#include "lib_for_cub3D.h"

/*void	ft_position_coordinates(char **splitted_str, int *x, int *y);
void	flood_fill(char **tab, t_point size, t_point begin);

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
}*/
