/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:48:46 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 13:21:04 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static t_parser	*lstnew(char **content)
{
	t_parser	*newcontent;

	newcontent = (t_parser *)galloc(sizeof(t_parser));
	if (!newcontent)
		return (NULL);
	newcontent->args = content;
	newcontent->next = NULL;
	return (newcontent);
}

static void	lstadd_back(t_parser **lst, t_parser *new)
{
	t_parser	*tmp;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

static int	pipe_counter(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\"')
				i++;
		}
		else if (str[i] == '|')
			count++;
		i++;
	}
	return (count);
}

static int	wordcount(char **s, int *i)
{
	int	count;

	count = 0;
	while (s[*i])
	{
		if (s[*i][0] == '|')
			break ;
		else
		{
			count++;
			(*i)++;
		}
	}
	// printf("count -> %d\n", count);
	return (count);
}

static int	finder(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '|')
		return (1);
	return (0);
}

t_parser	*parser(t_minishell *minishell, t_parser *parser, t_lexer *lexer)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**args;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	if (lexer->cmd[0])
	{
		while (i < pipe_counter(minishell->input) + 1)
		{
			args = (char **)galloc(sizeof(char *) * ((wordcount(lexer->cmd, &l)
							+ 1)));
			while (lexer->cmd[j] && !finder(lexer->cmd[j]))
			{
				args[k] = ft_strdup(lexer->cmd[j]);
				j++;
				k++;
			}
			args[k] = NULL;
			lstadd_back(&parser, lstnew(args));
			j++;
			i++;
			l++;
			k = 0;
		}
	}
	return (parser);
}
