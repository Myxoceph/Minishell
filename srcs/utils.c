/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:57:17 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 13:13:39 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

int	is_whitespace_ll(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	quote_check(const char *str, size_t start)
{
	bool	in_single;
	bool	in_double;
	size_t	i;

	in_single = false;
	in_double = false;
	i = 0;
	while (str[i] != '\0' && i < start)
	{
		if (str[i] == '\'' && in_double == false)
			in_single = !in_single;
		if (str[i] == '\"' && in_single == false)
			in_double = !in_double;
		i++;
	}
	if (in_double == true)
		return (1);
	else if (in_single == true)
		return (1);
	else
		return (0);
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	if (args)
	{
		while (args[i])
		{
			gfree(args[i]);
			i++;
		}
		gfree(args);
	}
	args = NULL;
}

t_parser	*free_list_array(t_parser *parser)
{
	t_parser	*tmp;

	while (parser)
	{
		tmp = parser;
		parser = parser->next;
		free_args(tmp->args);
		gfree(tmp);
	}
	parser = NULL;
	return (parser);
}

void	signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}
