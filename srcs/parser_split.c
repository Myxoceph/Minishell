/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:59:05 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/12 16:46:26 by abakirca         ###   ########.fr       */
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

static int	word_counter(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\'' && str[i] != '\"')
				i++;
			count++;
			i++;
		}
		else if (str[i] != ' ')
		{
			while (str[i] && str[i] != ' ')
			{
				if (str[i] == '<' || str[i + 1] == '<')
				{
					i += 2;
					count++;
				}
				else if (str[i] == '>' || str[i + 1] == '>')
				{
					i += 2;
					count++;
				}
				else if (str[i] == '<' || str[i] == '>')
				{
					i++;
					count++;
				}
				else if (str[i] == '|')
				{
					i++;
					count++;
				}
				else
				{
					i++;
					if (str[i] == ' ')
						count++;
				}
			}
		}
		else
			i++;
	}
	printf("--wordcount: %d--\n", count);
	return (count);
}

static int	word_len(char *s)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			i++;
			len++;
			while (s[i] && s[i] != '\'' && s[i] != '\"')
			{
				len++;
				i++;
			}
			i++;
			len++;
			break;
		}
		else if (s[i] == ' ' && s[i + 1] == '\'' || s[i + 1] == '\"')
		{
			len++;
			i++;
		}
		else if ((s[i] == '<' && s[i + 1] == '<') || (s[i] == '>' || s[i + 1] == '>'))
		{
			i += 2;
			len += 2;
			while (s[i] && s[i] == ' ')
			{
				len++;
				i++;
			}
			while (s[i] && s[i] != ' ')
			{
				if (s[i] == '\'' || s[i] == '\"')
				{
					i++;
					len++;
					while (s[i] && s[i] != '\'' && s[i] != '\"')
					{
						len++;
						i++;
					}
					i++;
					len++;
				}
				else
				{
					len++;
					i++;
				}
			}
		}
		else if (s[i] == '<' || s[i] == '>')
		{
			i++;
			len++;
			while (s[i] && s[i] == ' ')
			{
				len++;
				i++;
			}
			while (s[i] && s[i] != ' ')
			{
				if (s[i] == '\'' || s[i] == '\"')
				{
					i++;
					len++;
					while (s[i] && s[i] != '\'' && s[i] != '\"')
					{
						len++;
						i++;
					}
					i++;
					len++;
				}
				else
				{
					len++;
					i++;
				}
			}
		}
		else if (s[i] == ' ')
			break ;
		else
		{
			len++;
			i++;
			if (s[i] == '<' || s[i] == '>')
			{
				break ;
			}
		}
	}
	return (len);
}

char	**ft_parser_split(char *s, char c)
{
	char	**res;
	int		a;
	int		i;

	a = 0;
	i = 0;
	if (!s)
		return (NULL);
	res = (char **)galloc(sizeof(char *) * (word_counter(s) + 1));
	if (!res)
		return (NULL);
	while (a < word_counter(s))
	{
		while (s[i] && s[i] == c)
			i++;
		res[a] = ft_substr(s, i, word_len(&s[i]));
		if (!res[a])
			return (merror(res, 0));
		res[a] = ft_strtrim(res[a], " ");
		i += word_len(&s[i]);
		a++;
	}
	res[a] = NULL;
	return (res);
}
