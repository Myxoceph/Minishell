/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:34:04 by abakirca          #+#    #+#             */
/*   Updated: 2024/08/01 11:34:32 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

t_minishell	*get_minishell(void)
{
	static t_minishell	minishell;

	return (&minishell);
}

static void	starting(void)
{
	ft_printf(BIGREEN "\033[H\033[J");
	ft_printf("   _____   __        __        __            __   __\n");
	usleep(100000);
	ft_printf("  /     \\ |__| ____ |__| _____|  |__   ____ |  | |  |\n");
	usleep(100000);
	ft_printf(" /  \\ /  \\|  |/    \\|  |/  ___/  |  \\_/ __ \\|  | |  |\n");
	usleep(100000);
	ft_printf("/    Y    \\  |   |  \\  |\\___ \\|   Y  \\  ___/|  |_|  |__\n");
	usleep(100000);
	ft_printf("\\____|__  /__|___|  /__/____  >___|  /\\___  >____/____/\n");
	usleep(100000);
	ft_printf("        \\/        \\/        \\/     \\/     \\/\n" RESET);
	usleep(600000);
	ft_printf(BIBLACK "\nCREATED BY:\n");
	usleep(600000);
	ft_printf("\t\t _________________");
	ft_printf("\n\t\t/                 \\\n");
	ft_printf("\t\t| ytop & abakirca |\n");
	ft_printf("\t\t\\_________________/\n");
	ft_printf("\n\n" RESET);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*minishell;
	char		*input;
	int	i = -1;

	minishell = get_minishell();
	if (argc != 1)
	{
		ft_putstr_fd(BIRED "Error: No args needed.\n" RESET, 2);
		return (1);
	}
	//starting();
	*minishell = init_minishell(minishell, envp);
	while (1)
	{
		input = addgarbage(readline(BIBLUE "minishell > " RESET));
		if (!input)
			break ;
		minishell->input = input;
		lexer_parser(minishell, minishell->lexer);
		while (minishell->lexer->cmd[++i])
			ft_printf("Lexer input[%d]: $%s$\n", i, minishell->lexer->cmd[i]);
		i = -1;
		if (minishell->lexer->cmd)
			free_2D_array(minishell->lexer->cmd);
		if (minishell->parser->args)
			minishell->parser = free_list_array(minishell->parser);
		add_history(input);
		if (ft_strncmp(input, "exit", 4) == 0)
			break ;
		i = -1;
	}
	clear_garbage();
}
