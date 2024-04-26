/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 16:41:43 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:38:28 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	check_borders(t_parsing *parsing, int ind, int jind)
{
	int	**moves;
	int	i;
	int	new_ind;
	int	new_jind;

	i = 0;
	moves = NULL;
	moves = malloc(8 * sizeof(int *));
	if (moves == NULL)
		ft_error_in_malloc_exit();
	ft_for_check_borders_one(moves);
	assign_direct(moves);
	i = 0;
	while (i < 8)
	{
		new_ind = ind + moves[i][0];
		new_jind = jind + moves[i][1];
		ft_for_check_borders_two(parsing, new_ind, new_jind);
		i++;
	}
	free_arr(moves);
	return ;
}

void	ft_for_ft_check_map_check(t_parsing *parsing, int i, int j)
{
	if ((i == 0 || j == 0 || i == parsing->height - 1
			|| j == parsing->width - 1)
		&& (parsing->map[i][j] == '0'
		|| is_pl_pos(parsing->map[i][j])))
	{
		ft_put_error("Error: Map is not closed");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_check_map(t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	fix_player_pos(parsing);
	map_in_the_end(parsing);
	while (i < parsing->height)
	{
		j = 0;
		while (j < parsing->width)
		{
			ft_for_ft_check_map_check(parsing, i, j);
			if (parsing->map[i][j] == ' ' || parsing->map[i][j] == '\0'
				|| parsing->map[i][j] == '\n' || parsing->map[i][j] == '\t')
				check_borders(parsing, i, j);
			j++;
		}
		i++;
	}
	return ;
}

int	check_char(char c, const char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

void	ft_for_check_borders_one(int	**moves)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		moves[i] = malloc(2 * sizeof(int));
		if (moves[i] == NULL)
			ft_error_in_malloc_exit();
		i++;
	}
	return ;
}
