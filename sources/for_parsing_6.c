/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_parsing_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:07:34 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/23 21:27:12 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

char	*ft_strjoin_n(char *s1, char *s2)
{
	char	*joined;
	char	*result;

	joined = ft_strjoin(s1, "\n");
	result = ft_strjoin(joined, s2);
	return (result);
}

void	join_attribute_path(char **attribute, char *line, int *count)
{
	char	*new_path;

	new_path = ft_strjoin_n(*attribute, line);
	*attribute = new_path;
	(*count)++;
}

void	assign_path(t_parsing	*parsing, char *type, char *path)
{
	if (ft_strncmp(type, "NO", ft_strlen(type)) == 0)
		join_attribute_path(&parsing->attr.no, path,
			&parsing->attr.count.no_count);
	else if (ft_strncmp(type, "SO", ft_strlen(type)) == 0)
		join_attribute_path(&parsing->attr.so, path,
			&parsing->attr.count.so_count);
	else if (ft_strncmp(type, "WE", ft_strlen(type)) == 0)
		join_attribute_path(&parsing->attr.we, path,
			&parsing->attr.count.we_count);
	else if (ft_strncmp(type, "EA", ft_strlen(type)) == 0)
		join_attribute_path(&parsing->attr.ea, path,
			&parsing->attr.count.ea_count);
	else if (ft_strncmp(type, "F", ft_strlen(type)) == 0)
	{
		free(parsing->attr.f);
		parsing->attr.f = ft_strdup(path);
		parsing->attr.count.f_count++;
	}
	else if (ft_strncmp(type, "C", ft_strlen(type)) == 0)
	{
		free(parsing->attr.c);
		parsing->attr.c = ft_strdup(path);
		parsing->attr.count.c_count++;
	}
}

void	ft_for_is_attribute_check_word_count(int word_count, int num)
{
	if (num == 1)
	{
		if (word_count > 1)
		{
			ft_put_error("Error: Many arguments for attribute");
			exit(EXIT_FAILURE);
		}
		return ;
	}
	if (word_count == 1)
	{
		ft_put_error("Error: Attribute identifier missing");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	is_attribute(t_parsing *parsing, char *line)
{
	char	*token;
	char	*type;
	int		word_count;

	token = my_strtok(line, DELIM);
	type = NULL;
	word_count = 0;
	while (token)
	{
		if (word_count == 0)
		{
			if (is_attr(token))
				type = token;
			else
				return (0);
		}
		if (word_count == 1)
			assign_path(parsing, type, token);
		ft_for_is_attribute_check_word_count(word_count, 1);
		token = my_strtok(NULL, DELIM);
		word_count++;
	}
	ft_for_is_attribute_check_word_count(word_count, 2);
	return (1);
}
