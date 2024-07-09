/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:59:05 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/09 20:07:42 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

// char	**ft_parser_split(char *s, char c)
// {
// 	char	**res;
// 	int		a;
// 	int		i;

// 	a = -1;
// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	res = (char **)galloc(sizeof(char *) * (lexer_word_counter(s, c, 0, 1) + 1));
// 	if (!res)
// 		return (NULL);
// 	while (++a < lexer_word_counter(s, c, 0, 1))
// 	{
// 		res[a] = ft_substr(s, i, lexer_word_len(&s[i], 0, 0));
// 		if (!res[a])
// 			return (merror(res, 0));
// 		i += lexer_word_len(&s[i], 0, 0);
// 	}
// 	res[a] = NULL;
// 	return (res);
// }
