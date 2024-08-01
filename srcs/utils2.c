/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:45:16 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 13:56:27 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Minishell.h"

static char	*ft_strjoin_char(char *s1, char c)
{
	char	*result;
	int		len;

	if (!s1)
	{
		result = galloc(2);
		if (!result)
			return (NULL);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	len = ft_strlen(s1);
	result = galloc(len + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len + 1);
	result[len] = c;
	result[len + 1] = '\0';
	gfree(s1);
	return (result);
}

static void	remove_quotes_helper(char **tmp2, char **tmp, char **new_tmp)
{
	int	k;
	int	quote;

	k = -1;
	quote = 0;
	while ((*tmp2)[++k])
	{
		if (quote == 0 && ((*tmp2)[k] == '\'' || (*tmp2)[k] == '\"'))
			quote = (*tmp2)[k];
		else if (quote != 0 && quote == (*tmp2)[k])
			quote = 0;
		else
		{
			*new_tmp = ft_strjoin_char(*tmp, (*tmp2)[k]);
			if (!(*new_tmp))
				return ;
			*tmp = *new_tmp;
		}
	}
}

void	remove_quotes(char **args)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*new_tmp;

	i = -1;
	while (args[++i])
	{
		tmp = ft_strdup("");
		if (!tmp)
			return ;
		tmp2 = args[i];
		remove_quotes_helper(&tmp2, &tmp, &new_tmp);
		args[i] = tmp;
		gfree(tmp2);
	}
}

