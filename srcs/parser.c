/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:48:46 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/11 19:48:28 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static void	*add_node(t_parser **head)
{
	t_parser	*new_node;
	t_parser	*temp;

	new_node = (t_parser *)galloc(sizeof(t_parser));
	if (!new_node)
	{
		ft_putstr_fd(MALL_ERR, 2);
		clear_garbage();
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
	return (head);
}

static	bool	is_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			return (true);
		i++;
	}
	return (false);
}

static int	arraycount(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\0')
			break ;
		i++;
	}
	return (i);
}

static int	wordcount(char *str)
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
		}
		else if (str[i] != ' ')
		{
			while (str[i] && str[i] != ' ')
				i++;
			count++;
		}
		i++;
	}
	// printf("--wordcount: %d--\n", count);
	return (count);
}

void	parser(t_minishell *minishell, t_parser *parser, t_lexer *lexer)
{
	int	i;

	i = 0;
	while (i < arraycount(lexer->cmd))
	{
		add_node(&parser);
		parser->args = ft_parser_split(lexer->cmd[i], ' ');
		if (is_pipe(lexer->cmd[i]))
			parser->pipe = true;
		else
			parser->pipe = false;
		parser = parser->next;
		i++;
	}
}
