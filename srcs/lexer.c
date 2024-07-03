/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:27:24 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/03 18:27:38 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

void	lexer(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			ft_printf("SPACE\n");
		else if (line[i] == '|')
			ft_printf("PIPE\n");
		else if (line[i] == ';')
			ft_printf("SEMICOLON\n");
		else if (line[i] == '>')
			ft_printf("REDIRECT\n");
		else if (line[i] == '<')
			ft_printf("REDIRECT\n");
		else
			ft_printf("CHARACTER\n");
		i++;
	}
}
