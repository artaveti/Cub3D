/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_9.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:38:21 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 15:43:36 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	check_map_sym(t_parsing *parsing)
{
	int	i;
	int	j;

	i = 0;
	while (i < parsing->height)
	{
		j = 0;
		while (j < parsing->width)
		{
			if (parsing->map[i][j] != '0' && parsing->map[i][j] != '1'
				&& !is_space(parsing->map[i][j])
				&& !is_pl_pos(parsing->map[i][j]))
			{
				ft_put_error("Error: Invalid map symbol");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
	return ;
}

void	check_player_count(int player_count)
{
	if (player_count != 1)
	{
		if (player_count == 0)
			ft_put_error("Error: Player position not found");
		else
			ft_put_error("Error: Multiple player positions found");
		exit(EXIT_FAILURE);
	}
	return ;
}

void	fix_player_pos(t_parsing *parsing)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < parsing->height)
	{
		j = 0;
		while (j < parsing->width)
		{
			if (is_pl_pos(parsing->map[i][j]))
			{
				parsing->attr.direction_angle[0] = parsing->map[i][j];
				player_count++;
				parsing->player.x = i;
				parsing->player.y = j;
			}
			j++;
		}
		i++;
	}
	check_player_count(player_count);
	return ;
}

void	inv_sym(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_space(line[i]) && !is_valid_symbol(line[i]))
		{
			ft_put_error("Error: Invalid symbol found");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}
