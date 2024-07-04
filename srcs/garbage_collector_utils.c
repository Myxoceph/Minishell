/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:49:30 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/04 19:48:06 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

t_garbcol	**getgarbage(void) // Program boyunca kullanılacak garbage collector'ü döndürür
{
	static t_garbcol	*collector;

	return (&collector);
}
