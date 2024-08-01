/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:44:50 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 12:49:54 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Minishell.h"

void	ft_env(t_minishell *minishell)
{
	t_env	*env_data;

	env_data = minishell->env;
	while (env_data && ft_printf("%s=%s\n", env_data->key, env_data->value))
		env_data = env_data->next;
}
