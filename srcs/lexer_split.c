/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:55:43 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/11 19:26:58 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static char	**merror(char **arr, size_t i)
{
	while (arr[i])
		gfree(arr[i++]);
	gfree(arr);
	return (NULL);
}

static int	lexer_word_counter(char *s, char c, int i, int len)
{
	while(s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == '|')
			len++;
		else if ((s[i] == '<' && s[i + 1] == '<' ) || (s[i] == '>' && s[i + 1] == '>'))
		{
			len++;
			i++;
		}
		else if (s[i] == '<' || s[i] == '>')
			len++;
		i++;
	}
	// printf("--girdi | wordcount -> %d\n", len);
	return (len);
}

static int	handle_directs(char *s, int i, int len, int quotes)
{
	if (s[i] == '<' && s[i + 1] == '<')
	{
		i += 2;
		len += 2;
		while (s[i] == ' ' && i++)
			len++;
		while ((s[i] && (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != ' ')) && i++)
			len++;
	}
	else if (s[i] == '>' && s[i + 1] == '>')
	{
		i += 2;
		len += 2;
		while (s[i] == ' ' && i++)
			len++;
		while ((s[i] && (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != ' ')) && i++)
			len++;
	}
	else if (s[i] == '<')
	{
		i++;
		len++;
		while (s[i] == ' ' && i++)
			len++;
		while ((s[i] && (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != ' ')) && i++)
			len++;
	}
	else if (s[i] == '>')
	{
		i++;
		len++;
		while (s[i] == ' ' && i++)
			len++;
		while ((s[i] && (s[i] != '<' && s[i] != '>' && s[i] != '|' && s[i] != ' ')) && i++)
			len++;
	}
	return (len);
}

static int	lexer_word_len(char *s, int i, int len)
{
	int	quotes;

	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			quotes = s[i];
			i++;
			len++;
			while (s[i] && s[i] != quotes)
			{
				i++;
				len++;
			}
				i++;
				len++;
		}
		if (s[i] == '|')
		{
			len++;
			break;
		}
		else if (s[i] == '<' && s[i + 1] == '<')
		{
			len += handle_directs(s, i, 0, 0);
			break;
		}
		else if (s[i] == '>' && s[i + 1] == '>')
		{
			len += handle_directs(s, i, 0, 0);
			break;
		}
		else if (s[i] == '<')
		{
			len += handle_directs(s, i, 0, 0);
			break;
		}
		else if (s[i] == '>')
		{
			len += handle_directs(s, i, 0, 0);
			break;
		}
		i++;
		len++;
	}
	// printf("--girdi | wordlen -> %d\n", len);
	return (len);
}

char	**ft_lexer_split(char *s, char c)
{
	char	**res;
	int		a;
	int		i;

	a = -1;
	i = 0;
	if (!s)
		return (NULL);
	res = (char **)galloc(sizeof(char *) * (lexer_word_counter(s, c, 0, 1) + 1));
	if (!res)
		return (NULL);
	while (++a < lexer_word_counter(s, c, 0, 1))
	{
		res[a] = ft_substr(s, i, lexer_word_len(&s[i], 0, 0));
		if (!res[a])
			return (merror(res, 0));
		i += lexer_word_len(&s[i], 0, 0);
	}
	res[a] = NULL;
	return (res);
}
