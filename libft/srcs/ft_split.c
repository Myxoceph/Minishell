/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:36:05 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/09 11:21:57 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <stdio.h>
static char	**merror(char **arr, size_t i)
{
	while (arr[i])
		gfree(arr[i++]);
	gfree(arr);
	return (NULL);
}

static int	word_counter(char const *s, char c, size_t i)
{
	while (*s)
	{
		if (*s == '\"' || *s == '\'')
		{
			s++;
			while (*s)
				if (*s++ && (*s == '\"' || *s == '\''))
					break ;
			if (*s == '\"' || *s == '\'')
				s++;
			i++;
		}
		if (*s == c)
			s++;
		else if (*s)
		{
			while (*s && *s != c)
				if (*s++ && (*s == '\"' || *s == '\''))
					break ;
			i++;
		}
	}
	printf("i = %zu\n", i);
	return (i);
}

static int	word_len(char const *s, char c, int len)
{
	if (!*s)
		return (0);
	if (*s == '"' || *s == '\'')
	{
		s++;
		len += 2;
		while (*s)
		{
			len++;
			if (*s++ && (*s == '"' || *s == '\''))
				break ;
		}
		if (*s == '"' || *s == '\'')
			s++;
	}
	else
		while (*s && *s != c)
		{
			len++;
			if (*s++ && (*s == '\"' || *s == '\''))
				break ;
		}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		a;
	int		i;

	a = -1;
	i = 0;
	res = (char **)galloc(sizeof(char *) * (word_counter(s, c, 0) + 1));
	if (!s || !res)
		return (NULL);
	while (++a < word_counter(s, c, 0))
	{
		while (s[i] && s[i] == c)
			i++;
		res[a] = ft_substr(s, i, word_len(&s[i], c, 0));
		if (!res[a])
			return (merror(res, 0));
		i += word_len(&s[i], c, 0);
	}
	res[a] = NULL;
	return (res);
}
