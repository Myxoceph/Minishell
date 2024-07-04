/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:33:30 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/04 17:00:45 by abakirca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
# include <curses.h>
# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

#ifndef GARBAGE_COLLECTOR
# define GARBAGE_COLLECTOR 0
#endif

# define BIBLACK "\033[1;90m"
# define BIRED "\033[1;91m"
# define BIGREEN "\033[1;92m"
# define BIYELLOW "\033[1;93m"
# define BIBLUE "\033[1;94m"
# define BIMAGENTA "\033[1;95m"
# define BICYAN "\033[1;96m"
# define BIWHITE "\033[1;97m"
# define RESET "\033[0m"

int			g_status = 0;

typedef struct s_garbcol
{
	void				*content;
	struct s_garbcol	*next;
	struct s_garbcol	*previous;
}	t_garbcol;

int			minishell(char **envp);
void		lexer(char *line);

void		gfree(void *address);
void		*addgarbage(void *address);
void		*galloc(size_t size);
void		clear_garbage(void);
t_garbcol	**getgarbage(void);

#endif
