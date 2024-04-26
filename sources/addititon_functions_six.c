/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addititon_functions_six.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:39:32 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:39:34 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

void	ft_for_ft_memset_by_one_only_map(t_data *game, int quant_for_map)
{
	int	j;

	j = 0;
	while (j < quant_for_map)
	{
		game->map_array[j] = malloc(sizeof(char) * (game->map_max_width + 1));
		if (game->map_array[j] == NULL)
			ft_error_in_malloc_exit();
		game->map_array[j] = ft_memset(game->map_array[j], '1',
				game->map_max_width);
		game->map_array[j][game->map_max_width] = '\0';
		j++;
	}
	game->map_array[j] = NULL;
	return ;
}
