/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 12:59:12 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 12:59:17 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/Minishell.h"

char	*get_pwd(void)
{
	char	pwd[4096];
	char	*path;

	path = getcwd(pwd, 4096);
	if (!path)
		return (perror("minishell: pwd: "), NULL);
	return (ft_printf("%s\n", path), path);
}
