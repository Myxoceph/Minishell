/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:48:46 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/09 20:14:01 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static void expander(t_minishell *minishell, t_lexer *lexer)
{

}

static int	arraycount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '|')
			count++;
		else if ((str[i] == '<' && str[i + 1] == '<') || (str[i] == '>' && str[i + 1] == '>'))
		{
			count++;
			i++;
		}
		else if (str[i] == '<' || str[i] == '>')
			count++;
		i++;
	}
	return (count);
}

void parser(t_minishell *minishell, t_parser *parser, t_lexer *lexer)
{
	printf("\narrcount -> %d\n", arraycount(minishell->input));
	parser->args = galloc(sizeof(char *) * (arraycount(minishell->input) + 1));
	if (!parser->args)
		return ;
	
}
