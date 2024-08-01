/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:41:11 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 14:19:52 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static void	check_pid(pid_t pid, t_minishell *minishell, char **args, int i)
{
	char	**envs;

	envs = array_copier(minishell->envp);
	if (pid == 0)
	{
		if (execve(minishell->path, args, envs) == -1)
		{
			ft_putstr_fd(minishell->path, STDERR_FILENO);
			ft_putstr_fd(": command not found\n", STDERR_FILENO);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, 0, 0);
		free_2D_array(envs);
	}
}

static char	*search_env(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (!ft_strncmp(temp->key, "PATH", 4))
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

static char	*find_path(t_minishell *minishell, char *cmd)
{
	char	*temp;
	char	**path_split;
	int		i;
	char	*path_list;
	char	*path_cmd;

	temp = ft_strjoin("/", cmd);
	path_list = search_env(minishell->env);
	path_split = ft_split(path_list, ':');
	i = -1;
	while (path_split[++i])
	{
		path_cmd = ft_strjoin(path_split[i], temp);
		if (access(path_cmd, F_OK) == 0)
		{
			free_2D_array(path_split);
			gfree(temp);
			return (path_cmd);
		}
		free(path_cmd);
	}
	free_2D_array(path_split);
	return (gfree(temp), cmd);
}

static int	create_fork(t_minishell *minishell, char **args, int i)
{
	pid_t	pid;

	if (ft_strncmp(args[i], "./", 2))
		minishell->path = find_path(minishell, args[i]);
	else
		minishell->path = args[i];
	pid = fork();
	check_pid(pid, minishell, args, i);
	return (SUCCESS);
}

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
	else
	create_fork(minishell, minishell->parser->args, 0);

}
