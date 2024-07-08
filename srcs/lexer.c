/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:24:40 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/08 15:03:35 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

int	syntax_error(t_minishell *minishell, t_lexer *lexer)
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

void	lexer_parser(t_minishell *minishell, t_lexer *lexer)
{
	if (syntax_error(minishell, lexer))
	{
		clear_garbage();
		exit(1);
	}
	lexer->cmd = ft_split(minishell->input, ' ');
	return ;
}
