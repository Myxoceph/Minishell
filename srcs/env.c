/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:00:32 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/08 13:55:11 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static t_env	*create_env_node(const char *key, const char *value)
{
	t_env	*new_node;

	new_node = (t_env *)galloc(sizeof(t_env));
	new_node->key = ft_strdup(key);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	add_env_node(t_env **head, const char *key, const char *value)
{
	t_env	*new_node;
	t_env	*current;

	new_node = create_env_node(key, value);
	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
		new_node->prev = current;
	}
}

t_env	*parse_env(char **env)
{
	t_env	*env_list;
	char	*key;
	char	*value;
	char	*equal_sign;
	int		key_len;
	int		i;

	i = -1;
	env_list = NULL;
	while (env[++i])
	{
		equal_sign = ft_strchr(env[i], '=');
		if (equal_sign)
		{
			key_len = equal_sign - env[i];
			key = (char *)galloc(key_len + 1);
			ft_strlcpy(key, env[i], key_len);
			key[key_len] = '\0';
			value = ft_strdup(equal_sign + 1);
			add_env_node(&env_list, key, value);
			gfree(key);
			gfree(value);
		}
	}
	return (env_list);
}
