/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:55:43 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/29 13:10:18 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static int	wordcount(char const *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (is_whitespace_ll(s[i]) == 0 && quote_check(s, i) == 0)
		{
			count++;
			while (s[i] && ((is_whitespace_ll(s[i]) == 0 && quote_check(s, i) \
			== 0) || quote_check(s, i) > 0))
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	wordlen(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && ((is_whitespace_ll(s[i]) == 0 && quote_check(s, i) == \
	0) || quote_check(s, i) > 0))
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_array(char **array, int j)
{
	while (j >= 0)
	{
		gfree(array[j]);
		array[j] = NULL;
		j--;
	}
	gfree(array);
	array = NULL;
	return (NULL);
}

char	**ft_lexer_split(char *s)
{
	int		i;
	int		j;
	int		strings;
	int		len;
	char	**res;

	i = 0;
	j = 0;
	strings = wordcount(s);
	res = (char **)galloc((strings + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < strings)
	{
		while (is_whitespace_ll(s[i]) == 1)
			i++;
		len = wordlen(s, i);
		res[j] = ft_substr(s, i, len);
		if (!res[j])
			return (free_array(res, j));
		i += len;
		j++;
	}
	res[j] = 0;
	return (res);
}
