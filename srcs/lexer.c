/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:24:40 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/07 18:19:24 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"
#include <stdio.h>

static int	eol_error (t_minishell *minishell, t_lexer *lexer)
{
	char *line;
	int	i;

	line = minishell->input;
	i = ft_strlen(line) - 1;
	while (i >= 0)
	{
		while (line[i] == ' ')
			i--;
		if (line[i] == '|')
			return (ft_printf("%s %s %s\n", ERR_TITLE, SYNTAX_ERR, "'newline'"), 1);
		else if (line[i] == '<' || line[i] == '>')
			return (ft_printf("%s %s %s\n", ERR_TITLE, SYNTAX_ERR, "'newline'"), 1);
		else
			return (0);
	}
	return (0);
}

static int	syntax_error(t_minishell *minishell, t_lexer *lexer)
{
	char *line;
	int	i;
	int	squote;
	int	dquote;

	line = minishell->input;
	squote = 0;
	dquote = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == '|' && line[i + 1] == '|')
			return (ft_printf("%s %s %s\n", ERR_TITLE, SYNTAX_ERR, "\'|\'"), 1);
		else if (line[i] == '\'')
			squote++;
		else if (line[i] == '\"')
			dquote++;
	}
	if (squote && squote % 2 != 0)
		return (ft_printf("%s %s %s\n", ERR_TITLE, SYNTAX_ERR, "\'\'\'"), 1);
	if (dquote && dquote % 2 != 0)
		return (ft_printf("%s %s %s\n", ERR_TITLE, SYNTAX_ERR, "\'\"\'"), 1);
	return (0);
}

static void printList(t_parser *head) {
	t_parser *tmp = head;
	int j = 0;
	while (tmp)
	{
		for (int m = 0; tmp->args[m] != NULL; m++)
		{
			printf("[%d.nci node] Parser Args[%d]: $%s$\n",j, m, tmp->args[m]);
		}
		tmp = tmp->next;
		j++;
	}
}

void	lexer_parser(t_minishell *minishell, t_lexer *lexer)
{
	int	i;

	i = -1;
	if (syntax_error(minishell, lexer))
		return ;
	if (eol_error(minishell, lexer))
		return ;
	lexer->cmd = ft_lexer_split(minishell->input);
	// while (minishell->lexer->cmd[++i])
	// 	ft_printf("Lexer input[%d]: $%s$\n", i, minishell->lexer->cmd[i]);
	minishell->parser = parser(minishell, minishell->parser, minishell->lexer);
	// printList(minishell->parser);
	if (minishell->parser)
	{
		remove_quotes(minishell->parser->args);
		executor(minishell);
	}
	printf("lexer_parser %p\n", lexer->cmd);
	return ;
}
