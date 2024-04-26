/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_7.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:28:01 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 21:27:59 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

int	is_valid(int row, int col, t_parsing *parsing)
{
	return (row >= 0 && row < parsing->height
		&& col >= 0 && col < parsing->width);
}

int	is_pl_pos(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	ft_for_check_borders_two(t_parsing *parsing, int new_ind,
			int new_jind)
{
	if (is_valid(new_ind, new_jind, parsing)
		&& (parsing->map[new_ind][new_jind] == '0'
		|| is_pl_pos(parsing->map[new_ind][new_jind])))
	{
		ft_put_error("Error: Map is not closed");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	assign_direct(int **moves)
{
	moves[0][0] = -1;
	moves[0][1] = 0;
	moves[1][0] = -1;
	moves[1][1] = -1;
	moves[2][0] = -1;
	moves[2][1] = 1;
	moves[3][0] = 1;
	moves[3][1] = 0;
	moves[4][0] = 1;
	moves[4][1] = -1;
	moves[5][0] = 1;
	moves[5][1] = 1;
	moves[6][0] = 0;
	moves[6][1] = -1;
	moves[7][0] = 0;
	moves[7][1] = 1;
	return ;
}

void	free_arr(int **arr)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
