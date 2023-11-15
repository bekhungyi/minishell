/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:04:05 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/15 23:44:15 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void execute_command(const char *command, char *const args[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {  // Child process
        // Set the PATH to /bin
        setenv("PATH", "/bin", 1);

        // Print the current PATH (optional)
        printf("PATH: %s\n", getenv("PATH"));

        // If the command contains a '/' (indicating an absolute path), use it as is
        if (strchr(command, '/')) {
            execve(command, args, NULL);
        } else {
            // If the command doesn't contain a '/', prepend '/bin/' and execute
            char path_command[1024];
            snprintf(path_command, sizeof(path_command), "/bin/%s", command);
            execve(path_command, args, NULL);
        }

        // If execve fails, print an error
        perror("execve failed");
        exit(EXIT_FAILURE);
    } else {  // Parent process
        waitpid(pid, NULL, 0);
    }
}

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
		if (entry->d_name[0] != '.') {
			printf("%-20s", entry->d_name);
			pcount++;
			if (pcount % 5 == 0)
				printf("\n");
		}
	}
	printf("\n");
	closedir(dir);
}

void	run_builtins(t_promt *promt, char **envp)
{
	int	i;
	char *const args[] = {promt->command, NULL};

	i = 0;
	// execute_command(promt->command, args);
	if (ft_strncmp(promt->command, "ls", 2) == 0)
		ft_ls();
	else if (ft_strncmp(promt->command, "echo", 4) == 0)
		ft_echo(promt);
	else if (ft_strncmp(promt->command, "pwd", 3) == 0)
		printf("%s\n", getcwd(NULL, 0));
	else if (ft_strncmp(promt->command, "cd", 2) == 0)
		ft_cd(promt, envp);
	else if (ft_strncmp(promt->command, "env", 3) == 0)
		ft_env(envp);
	else if (ft_strncmp(promt->command, "exit", 4) == 0)
		exit(0);
	else
		printf("minishell: command not found: %s\n", promt->command);
}

void	parsing(t_promt *promt, char **envp)
{
	t_commandnode *command_node;
	t_pipenode *pipe_node;
	t_redirectionnode *redirection_node;

	
	
}

void	ft_token(char *str, t_promt *promt, char **envp)
{
	int	i;

	if (*str == 0)
		return ;
	i = -1;
	promt->has_pipe = 0;
	promt->has_redir = 0;
	add_history(str);
	promt->argv = ft_split(str, ' ');
	promt->command = promt->argv[0];
	while (promt->argv[++i])
	{
		if (ft_strlen(promt->argv[i]) == 1)
		{
			if (promt->argv[i][0] == '|')
				promt->has_pipe = 1;
			else if (promt->argv[i][0] == '>' || promt->argv[i][0] == '<')
				promt->has_redir = 1;
		}
	}
	run_builtins(promt, envp);
}

// char* ft_readline(const char *prompt)
// {
// 	char *buffer;
	
// 	buffer = readline(prompt);
// 	if (!buffer) {
// 		return NULL;
// 	}
// 	if (strlen(buffer) > 0) {
// 		add_history(buffer);
// 	}
// 	return buffer;
// }

// Example AST for the command: "ls -l | grep .txt > output.txt"

void	minishell(char **envp)
{
	t_promt	promt;
	int		status = 0;
	char	*buffer;
	char	**args;
	char	*commands[] = {"ls", "echo", "pwd", "cd", "export", "unset", "env", "exit", NULL};

	while (status != -1) {
		signal_handler(0);
		// buffer = ft_readline("user1@minishell > ");
		if (!buffer)
			break ;
		ft_token(buffer, &promt, envp);
		if (strcmp(buffer, "exit") == 0)
			status = -1;
        free(buffer);
	}
}
