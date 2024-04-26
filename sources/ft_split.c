/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artaveti <artaveti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 19:18:34 by artaveti          #+#    #+#             */
/*   Updated: 2024/03/24 18:13:31 by artaveti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_for_cub3D.h"

static size_t	ft_start(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

static	size_t	ft_words_count(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i])
		{
			i++;
		}
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
			{
				i++;
			}
		}
	}
	return (count);
}

static void	ft_malloc_for_word(char **strs, const char	*s, char c)
{
	size_t	words;
	size_t	st;
	size_t	chars_count;
	size_t	start;

	words = ft_words_count(s, c);
	st = 0;
	chars_count = 0;
	start = ft_start(s, c);
	while (words-- > 0)
	{
		if (s[start])
		{
			while (s[start] == c && s[start])
				start++;
			while (s[start] != c && s[start])
			{
				chars_count++;
				start++;
			}
			strs[st++] = malloc(sizeof(char) * (chars_count + 1));
		}
		chars_count = 0;
	}
	strs[st] = 0;
}

char	**ft_split(char const	*s, char c)
{
	char	**strs;
	size_t	st;
	size_t	i;
	size_t	l;

	if (!s)
		ft_error_in_malloc_exit();
	strs = (char **)malloc(sizeof(char *) * (ft_words_count(s, c) + 1));
	if (!strs)
		ft_error_in_malloc_exit();
	ft_malloc_for_word(strs, s, c);
	ft_assign_in_ft_split(&st, &i, &l);
	while (st < ft_words_count(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			strs[st][l++] = s[i++];
		strs[st][l] = '\0';
		l = 0;
		st++;
	}
	return (strs);
}

void	ft_assign_in_ft_split(size_t *st, size_t *i, size_t *l)
{
	*st = 0;
	*i = 0;
	*l = 0;
	return ;
}
