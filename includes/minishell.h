/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:30:32 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/12 19:53:35 by bhung-yi         ###   ########.fr       */
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
#include <readline/readline.h>
#include <readline/history.h>

extern char **environ;  // Declare the global environment variable

typedef struct s_promt
{
    char	*command;
    char	**argv;
    // char	**envp;

    int     option;

}	t_promt;

void	minishell(char **envp);
void	ft_echo(t_promt *promt);
void    ft_cd(t_promt *promt);


#endif