/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_one.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:18:52 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:05:39 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_i;
	int		s2_i;
	char	*con;

	s1_i = 0;
	s2_i = 0;
	con = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!con)
		ft_error_in_malloc_exit();
	while (s1 && s1[s1_i] != '\0')
	{
		con[s1_i] = s1[s1_i];
		s1_i++;
	}
	while (s2 && s2[s2_i] != '\0')
	{
		con[s1_i] = s2[s2_i];
		s1_i++;
		s2_i++;
	}
	con[s1_i] = '\0';
	if (s1)
		free (s1);
	return (con);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (s + i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	while (s != 0 && s[i] != '\0')
	{
		i++;
	}
	return (i);
}
