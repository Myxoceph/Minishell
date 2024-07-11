/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:41:11 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/11 20:35:25 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static int finder(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strncmp(args[i], ">", 1) == 0)
			return (i + 1);
		i++;
	}
	return (0);
}

void	executor(t_minishell *minishell)
{
	pid_t	pid;
	int	status;
	int	fd;
	int	redir;

	redir = finder(minishell->parser->args);
	if (redir == 0)
	{
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		fd = open(minishell->parser->args[redir], O_RDWR | O_CREAT | O_TRUNC, 0644);
		dup2(fd, STDOUT_FILENO);
		close (fd);
		if (execve("/bin/echo", minishell->parser->args, minishell->envp) == -1)
			ft_printf("%s %s\n", ERR_TITLE, "execve error");
	}
	else
		waitpid(pid, &status, 0);

}
