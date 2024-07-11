/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:44:25 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/11 16:18:14 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

static void	toggle_quote_state(char c, bool *in_single_quotes, bool *in_double_quotes)
{
	if (c == '\'' && !(*in_double_quotes))
		*in_single_quotes = !(*in_single_quotes);
	else if (c == '\"' && !(*in_single_quotes))
		*in_double_quotes = !(*in_double_quotes);
}

static void	process_char(char c, char delimiter, char **output, int *out_index,
					bool *last_was_space, bool in_quotes)
{
	if (is_space(c))
	{
		if (!in_quotes)
		{
			if (!(*last_was_space))
			{
				(*output)[(*out_index)++] = delimiter;
				*last_was_space = true;
			}
		}
		else
			(*output)[(*out_index)++] = c;
	}
	else
	{
		(*output)[(*out_index)++] = c;
		*last_was_space = false;
	}
}

static int	calculate_length(char *s)
{
	int	length = 0;

	while (s[length] != '\0')
		length++;
	return (length);
}

char	*ft_split_array(char *s, char c)
{
	char	*output;
	int		length;
	int		i;
	int		out_index;
	bool	in_single_quotes;
	bool	in_double_quotes;
	bool	last_was_space;

	length = calculate_length(s);
	output = (char *)galloc(length + 1);
	if (output == NULL)
		return (NULL);
	i = 0;
	out_index = 0;
	in_single_quotes = false;
	in_double_quotes = false;
	last_was_space = false;
	while (s[i] != '\0')
	{
		toggle_quote_state(s[i], &in_single_quotes, &in_double_quotes);
		process_char(s[i], c, &output, &out_index, &last_was_space,
					in_single_quotes || in_double_quotes);
		i++;
	}
	output[out_index] = '\0';
	return (output);
}
