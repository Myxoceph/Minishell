/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:10:41 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/07 20:58:11 by abakirca         ###   ########.fr       */
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

static int	count_cols(char *array)
{
	return (strlen(array));
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
		cols = count_cols(src[i]);
		dest[i] = (char *)galloc((cols + 1) * sizeof(char));
		if (!dest[i])
		{
			while (i > 0)
				free(dest[--i]);
			free(dest);
			return (NULL);
		}
		ft_memcpy(dest[i], src[i], (cols + 1) * sizeof(char));
	}
	dest[rows] = NULL;
	return (dest);
}

t_minishell	init_minishell(t_minishell *minishell, char **envp)
{
	minishell = galloc(sizeof(t_minishell));
	minishell->env = galloc(sizeof(t_env));
	minishell->cmds = galloc(sizeof(t_cmds));
	minishell->envp = array_copier(envp);
	return (*minishell);
}
