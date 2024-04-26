/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:21:59 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 19:23:35 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

char	*ft_check(char *buf, char *result, int i)
{
	if (buf[i] == '\n')
	{
		result[i] = '\n';
		result[i + 1] = '\0';
	}
	else
	{
		result[i] = '\0';
		free(buf);
		buf = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	buf_index;
	static int	bytes_read;
	char		*result;
	int			i;

	if (ft_assign_result_in_get_next_line(fd, &result, &i) == 0)
		return (NULL);
	while (1)
	{
		if (buf_index >= bytes_read)
			if (ft_ft_check_in_get_next_line_one(&buf_index, &bytes_read, fd,
					buf) == 0)
				break ;
		if (buf[buf_index] == '\n')
			return (ft_ft_check_in_get_next_line_two(result, i, &buf_index));
		else if (buf[buf_index] == '\0')
			return (ft_ft_check_in_get_next_line_three(result, i, &buf_index));
		ft_for_get_next_line(result, &i, buf, &buf_index);
		if (i >= BUFFER_SIZE)
			return (ft_free_and_return_null_in_get_next_line(result));
	}
	if (i > 0)
		return (ft_check_in_get_next_line_five(result, i));
	return (ft_free_and_return_null_in_get_next_line(result));
}
