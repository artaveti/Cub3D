#include "lib_for_cub3D.h"

void	ft_check_first_line(char *first_line)
{
	int	i;

	i = 0;
	while (first_line[i] != '\0')
	{
		if (first_line[i] != '1')
		{
			ft_put_error("Error: Wrong character in first line");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	ft_check_middle_line(char *middle_line)
{
	int	i;

	if (middle_line[0] != '1')
	{
		ft_put_error("Error: Wrong character in middle line");
		exit(EXIT_FAILURE);
	}
	i = 1;
	while (middle_line[i + 1] != '\0')
	{
		if (middle_line[i] != '0' && middle_line[i] != '1'
			&& middle_line[i] != 'C' && middle_line[i] != 'E'
			&& middle_line[i] != 'P' && middle_line[i] != 'W')
		{
			ft_put_error("Error: Wrong character in middle line");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (middle_line[i] != '1')
	{
		ft_put_error("Error: Wrong character in middle line");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_check_last_line(char *first_line)
{
	int	i;

	i = 0;
	while (first_line[i] != '\0')
	{
		if (first_line[i] != '1')
		{
			ft_put_error("Error: Wrong character in last line");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

void	ft_check_characters(char **splitted_str)
{
	int	i;

	ft_check_first_line(splitted_str[0]);
	i = 1;
	while (splitted_str[i + 1] != '\0')
	{
		ft_check_middle_line(splitted_str[i]);
		i++;
	}
	ft_check_last_line(splitted_str[i]);
	return ;
}
