/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:41:11 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 13:00:00 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "echo", 4))
		return (1);
	else if (!ft_strncmp(cmd, "cd", 4))
		return (2);
	else if (!ft_strncmp(cmd, "pwd", 4))
		return (3);
	else if (!ft_strncmp(cmd, "export", 4))
		return (4);
	else if (!ft_strncmp(cmd, "unset", 4))
		return (5);
	else if (!ft_strncmp(cmd, "env", 4))
		return (6);
	else if (!ft_strncmp(cmd, "exit", 4))
		return (7);
	return (0);
}

void	executor(t_minishell *minishell)
{
	if (is_builtin(minishell->parser->args[0]) == 1)
		ft_echo(minishell->parser->args);
	// else if (is_builtin(minishell->parser->args[0]) == 2)
	// 	cd(minishell->parser->args);
	else if (is_builtin(minishell->parser->args[0]) == 3)
		get_pwd();
	// else if (is_builtin(minishell->parser->args[0]) == 4)
	// 	export(minishell->parser->args);
	// else if (is_builtin(minishell->parser->args[0]) == 5)
	// 	unset(minishell->parser->args);
	else if (is_builtin(minishell->parser->args[0]) == 6)
		ft_env(minishell);
	else if (is_builtin(minishell->parser->args[0]) == 7)
		exit(0);
}
