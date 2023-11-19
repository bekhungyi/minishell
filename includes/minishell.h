/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:30:32 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/17 14:30:18 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <term.h>
#include <readline/readline.h>
#include <readline/history.h>

extern char **environ;  // Declare the global environment variable

enum NodeType {
    COMMAND_NODE,
	VAR_NODE,
    PIPE_NODE,
    REDIRECTION_NODE,
};

typedef struct s_node {
    enum NodeType	type;
	int				node_count;
    struct s_node	*first_node;
    struct s_node	*next_node;
    struct s_node	*prev_node;

    char            **args;

	char			*value;

	int				in_quote;

}   t_node;

typedef struct s_commandnode
{
    t_node  base;
    char    *command;
    char    **argv;
}   t_commandnode;

typedef struct s_pipenode
{
    t_node  base;
    t_node  *left;
    t_node  *right;
}   t_pipenode;

typedef struct s_redirectionnode
{
    t_node  base;
    t_node  *command_node;
    char    *infile;
    char    *outfile;
}   t_redirectionnode;


typedef struct s_promt
{
    char	*command;
    char	**argv;
    int     has_pipe;
    int     has_redir;
    // char	**envp;

    int     option;

}	t_promt;

void	minishell(char **envp);
// void	ft_echo(t_promt *promt);
void ft_echo(t_node *node);
void    ft_cd(t_promt *promt, char **envp);
void    ft_env(char **envp);

void	signal_handler(int num);

#endif