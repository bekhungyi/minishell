/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:08 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/17 15:27:17 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char *concat_strings(const char *str1, const char *str2) {
    size_t len1 = ft_strlen(str1);
    size_t len2 = ft_strlen(str2);

    char *result = malloc(len1 + len2 + 1); // +1 for null terminator
    if (result == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    ft_memcpy(result, str1, len1);
    ft_memcpy(result + len1, str2, len2 + 1); // Copy null terminator
    return result;
}

char *find_command_path(const char *command, const char *env_path) {
    char *path_copy = ft_strdup(env_path);
    char *token_start = path_copy;
    char *token_end;

    while ((token_end = ft_strchr(token_start, ':')) != NULL) {
        *token_end = '\0'; // Null-terminate the token
        DIR *dir = opendir(token_start);
        struct dirent *entry;

        while ((entry = readdir(dir)) != NULL) {
            if (ft_strncmp(entry->d_name, command, ft_strlen(command)) == 0) {
                closedir(dir);
                char *full_path = concat_strings(token_start, "/");
                char *temp = concat_strings(full_path, entry->d_name);
                free(full_path);
                free(path_copy);
                return temp; // Found the executable
            }
        }

        closedir(dir);
        token_start = token_end + 1;
    }

    free(path_copy);
    return NULL; // Command not found in any PATH directory
}

int		quotecount(char *str)
{
	int	i;
	int count;

	i = -1;
	count = -1;
	while (str[++i])
	{
		if (str[i] == '\"')
			count++;
	}
	if (count % 2 == 0)
	{
		printf("Error: quote count\n");
		return (1);
	}
	else
		return (0); // correct
}

void	parse(char *str, t_node *node)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	node->args = malloc(sizeof(char *) * 1024);
	printf("str: %s\n", str);
	while (str[++i])
	{
		if (str[i] == '\"')
		{
			k = 0;
			node->args[j] = malloc(sizeof(char) * 1024);
			while (str[++i] != '\"' && str[i] != '\0')
			{
				node->args[j][k] = str[i];
				k++;
			}
			node->args[j][k] = '\0';
			j++;
			i--;
		}
		else if (str[i] != ' ')
		{
            k = 0;
            node->args[j] = malloc(sizeof(char) * 1024);
            while (str[i] != ' ' && str[i] != '\0')
			{
                node->args[j][k] = str[i];
                k++;
                i++;
        	}
			node->args[j][k] = '\0';
            j++;
			i--;
		}
	}
	node->args[j] = NULL;
	node->value = node->args[0];
}

void	ft_readline(t_node *node)
{
	char	*buffer;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	buffer = ft_strdup("\033[1;32m[minishell] \033[0m> ");
    // buffer = ft_strjoin(buffer, cwd);
	buffer = readline(buffer);
	if (!buffer)
		exit(0);
	if (quotecount(buffer))
		return ;
	if (ft_strncmp(buffer, "", 1))
		add_history(buffer);
	
	printf("Input: %s\n", buffer);
	parse(buffer, node);
	if (ft_strncmp(node->args[0], "echo", 4) == 0)
		ft_echo(node);
	free(buffer);
}

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		status;
	t_node	*node;
	char	*path;

	pid_t	pid;

	signal(SIGINT, signal_handler);
	node = malloc(sizeof(t_node));
	node->value = NULL;
	while (status != -1)
	{
		ft_readline(node);
		// for (int i = 0; node->args[i] != NULL; ++i)
		// {
		// 	printf("node->args[%d]: %s<\n", i, node->args[i]);
		// }
		path = find_command_path(node->args[0], getenv("PATH"));
		printf("path: %s\n", path);
		pid = fork();
		if (pid == 0)
		{
			if (execve(path, node->args[0], envp) == -1)
				printf("Error: execve\n");
		}
		else if (pid > 0)
			wait(NULL);
		else
			printf("Error: fork\n");

		if (node->value && ft_strncmp(node->value, "exit", 4) == 0)
			status = -1;
		if (line == NULL)
			break ;
		int x = 0;
		// while (node->args[x++])
		// 	free(node->args[x]);
		
	}
	
	return (0);
}

//	ls -l | grep .txt > output.txt	//
// ls - compare - found - settype - 
// 
// 