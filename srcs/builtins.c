/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:32:22 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/12 19:53:22 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void ft_echo(t_promt *promt) {
    int i;

    if (promt->argv[1] == NULL)
        printf("\n");
    else if (ft_strncmp(promt->argv[1], "-n", 2) == 0) {
        i = 2;
        printf("%s", promt->argv[i++]);
        while (promt->argv[i] != NULL)
            printf(" %s", promt->argv[i++]);
        printf("%%\n");
        return ;
    }
    else {
        i = 1;
        while (promt->argv[i] != NULL)
            printf("%s ", promt->argv[i++]);
        printf("\n");
        return ;
    }
}

void    ft_cd(t_promt *promt)
{
    if (promt->argv[1] == NULL)
        chdir(getenv("HOME"));
    else if (chdir(promt->argv[1]) == -1)
        printf("minishell: cd: %s: No such file or directory\n", promt->argv[1]);
    else
        chdir(promt->argv[1]);
    return ;
}