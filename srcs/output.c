/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:21:04 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/17 10:28:50 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    err(char *str)
{
    write(2, str, ft_strlen(str));
    exit(EXIT_FAILURE);
}

void    print_prompt(void)
{
    char *str;
    char	*cwd;

    str = ft_strdup("\033[1;32m[minishell] \033[0m");
	cwd = getcwd(NULL, 0);
	printf("%s", cwd);
    str = ft_strlcat(str, cwd, ft_strlen(str));
    readline(str);
}