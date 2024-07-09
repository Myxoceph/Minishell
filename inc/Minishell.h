/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abakirca <abakirca@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:33:30 by abakirca          #+#    #+#             */
/*   Updated: 2024/07/09 20:07:09 by abakirca         ###   ########.fr       */
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

# define BIBLACK "\033[1;90m"
# define BIRED "\033[1;91m"
# define BIGREEN "\033[1;92m"
# define BIYELLOW "\033[1;93m"
# define BIBLUE "\033[1;94m"
# define BIMAGENTA "\033[1;95m"
# define BICYAN "\033[1;96m"
# define BIWHITE "\033[1;97m"
# define RESET "\033[0m"

# define ERR_TITLE "minishell: "
# define SYNTAX_ERR "syntax error near unexpected token"

typedef struct s_lexer
{
	char			**cmd;
}				t_lexer;

typedef struct s_parser
{
	char			**args;
	struct s_parser	*next;
	struct s_parser	*prev;
}				t_parser;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_minishell
{
	t_env		*env;
	t_lexer		*lexer;
	t_parser	*parser;
	char		**envp;
	char		*input;
}				t_minishell;

t_minishell	*get_minishell(void);
t_minishell	init_minishell(t_minishell *minishell, char **envp);
t_env		*parse_env(char **env);
void		lexer_parser(t_minishell *minishell, t_lexer *lexer);
void		free_2D_array(t_lexer *lexer);
char		**ft_lexer_split(char *s, char c);
void 		parser(t_minishell *minishell, t_parser *parser, t_lexer *lexer);

#endif
