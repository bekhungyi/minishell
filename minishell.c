/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:04:05 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/09 17:15:55 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

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

void	echo(char *line)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	count = 0;
	char	*str;
	char	*str2;

	while (line[i] != '\0')
	{
		if (line[i] == '\"')
			count++;
		i++;
	}
	if (count % 2 != 0)
	{
		printf("Error! Invalid number of quotes.\n");
		return ;
	}
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"')
		{
			j = i + 1;
			while (line[j] != '\"')
				j++;
			str = (char *)malloc(sizeof(char) * (j - i));
			k = 0;
			while (i < j)
			{
				str[k] = line[i];
				i++;
				k++;
			}
			str[k] = '\0';
			printf("%s", str);
			free(str);
		}
		else if (line[i] == '\'')
		{
			j = i + 1;
			while (line[j] != '\'')
				j++;
			str2 = (char *)malloc(sizeof(char) * (j - i));
			k = 0;
			while (i < j)
			{
				str2[k] = line[i];
				i++;
				k++;
			}
			str2[k] = '\0';
			printf("%s", str2);
			free(str2);
		}
		else
			printf("%c", line[i]);
		i++;
	}
	printf("\n");
}

void	minishell(void)
{
	t_command	command;
	int		status = 0;
	char	*line;
	char	**args;

	do {
		command.line = readline("user1@minishell > ");
		add_history(command.line);
		if (strcmp(command.line, "exit") == 0)
			status = -1;
		if (strcmp(command.line, "ls") == 0)
			ft_ls();

		// printf("%s\n", command.line);
        free(command.line);
	} while (status != -1);
}
