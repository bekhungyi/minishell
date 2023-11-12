/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:04:05 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/12 19:52:02 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_ls(void)
{
	DIR *dir;
	struct dirent *entry;
	int	pcount = 0;

	dir = opendir(".");
	if (dir == NULL)
	{
		printf("Error! unable to open directory.\n");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		printf("%-20s", entry->d_name);
		pcount++;
		if (pcount % 5 == 0)
			printf("\n");
	}
	printf("\n");
}

void	ft_parse(t_promt *promt, char **envp)
{
	int	i;

	i = 0;
	if (ft_strncmp(promt->command, "ls", 2) == 0)
		ft_ls();
	else if (ft_strncmp(promt->command, "echo", 4) == 0)
		ft_echo(promt);
	else if (ft_strncmp(promt->command, "pwd", 3) == 0)
		printf("%s\n", getcwd(NULL, 0));
	else if (ft_strncmp(promt->command, "cd", 2) == 0)
		ft_cd(promt);
	else if (ft_strncmp(promt->command, "env", 3) == 0)
	{
		while (environ[i] != NULL)
			printf("%s\n", environ[i++]);
	}
	else if (ft_strncmp(promt->command, "exit", 4) == 0)
		exit(0);
	else
		printf("minishell: command not found: %s\n", promt->command);
}

void	ft_token(char *str, t_promt *promt, char **envp)
{
	int	i;

	i = 0;
	add_history(str);
	// promt->command = ft_substr(str, 0, ft_strchr(str, ' ') - str);
	promt->argv = ft_split(str, ' ');
	promt->command = promt->argv[0];
	ft_parse(promt, envp);
}

void	minishell(char **envp)
{
	t_promt	promt;
	int		status = 0;
	char	*buffer;
	char	**args;
	char	*commands[] = {"ls", "echo", "pwd", "cd", "export", "unset", "env", "exit", NULL};

	while (status != -1) {
		buffer = readline("user1@minishell > ");
		ft_token(buffer, &promt, envp);
		if (strcmp(buffer, "exit") == 0)
			status = -1;
		// if (strcmp(promt.command, "ls") == 0)
		// 	ft_ls();

        free(buffer);
	}
}
