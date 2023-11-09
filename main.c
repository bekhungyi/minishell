/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:08 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/09 15:22:22 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

void minishell(void) {
    char *line;
    char **args;
    int status;

    do {
        line = readline("user@1 > ");
		if (strcmp(line, "exit") == 0)
			status = -1;
		printf("%s\n", line);
        free(line);
    } while (status != -1);
}

int	main(int argc, char **argv)
{
	minishell();
	return (0);
}
