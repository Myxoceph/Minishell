/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:10:41 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 11:09:38 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static int	count_rows(char **array)
{
	int	rows;

	rows = 0;
	while (array[rows] != NULL)
		rows++;
	return (rows);
}

static char	**array_copier(char **src)
{
	char	**dest;
	int		rows;
	int		cols;
	int		i;

	rows = count_rows(src);
	dest = (char **)galloc((rows + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		cols = ft_strlen(src[i]);
		dest[i] = (char *)galloc((cols + 1) * sizeof(char));
		if (!dest[i])
		{
			while (i > 0)
				gfree(dest[--i]);
			gfree(dest);
			return (NULL);
		}
		ft_memcpy(dest[i], src[i], (cols + 1) * sizeof(char));
	}
	dest[rows] = NULL;
	return (dest);
}

void	free_2D_array(char **cmd)
{
	int	i;

	i = -1;
	if (!(*cmd))
		return ;
	while (cmd[++i])
		gfree(cmd[i]);
	if (*cmd)
		gfree(cmd);
}

t_minishell	init_minishell(t_minishell *minishell, char **envp)
{
	minishell = galloc(sizeof(t_minishell));
	ft_memset(minishell, 0, sizeof(t_minishell));
	minishell->env = galloc(sizeof(t_env));
	ft_memset(minishell->env, 0, sizeof(t_env));
	minishell->lexer = galloc(sizeof(t_lexer));
	ft_memset(minishell->lexer, 0, sizeof(t_lexer));
	minishell->parser = NULL;
	// minishell->parser = galloc(sizeof(t_parser));
	// ft_memset(minishell->parser, 0, sizeof(t_parser));
	minishell->envp = array_copier(envp);
	minishell->env = parse_env(minishell->envp);
	return (*minishell);
}
