/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:34:04 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/02 16:14:04 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Minishell.h"

void	starting(void)
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
	char	*line;

	starting();
	while (1)
	{
		line = readline(BICYAN "Minishell > " RESET);
		if (line == NULL)
			break ;
		
		if (line[0] != '\0')
			add_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}
