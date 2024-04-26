/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_two.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:20:00 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 19:21:45 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

int	ft_ft_check_in_get_next_line_one(int *buf_index, int *bytes_read,
		int fd, char buf[BUFFER_SIZE + 1])
{
	*buf_index = 0;
	*bytes_read = read(fd, buf, BUFFER_SIZE);
	if (*bytes_read <= 0)
		return (0);
	buf[*bytes_read] = '\0';
	return (1);
}

char	*ft_ft_check_in_get_next_line_two(char *result, int i, int *buf_index)
{
	result[i] = '\n';
	result[i + 1] = '\0';
	*buf_index = *buf_index + 1;
	return (result);
}

char	*ft_ft_check_in_get_next_line_three(char *result, int i, int *buf_index)
{
	if (i == 0)
		return (ft_free_and_return_null_in_get_next_line(result));
	return (ft_ft_check_in_get_next_line_four(result, i, buf_index));
}

char	*ft_ft_check_in_get_next_line_four(char *result, int i, int *buf_index)
{
	result[i] = '\0';
	*buf_index = *buf_index + 1;
	return (result);
}

char	*ft_check_in_get_next_line_five(char *result, int i)
{
	result[i] = '\0';
	return (result);
}
