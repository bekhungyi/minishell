/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:08 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/15 23:43:49 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_readline(t_node *node)
{
	char	*buffer;

	buffer = readline("[minishell] > ");
	if (!buffer)
		exit(0);
	if (ft_strncmp(buffer, "", 1))
		add_history(buffer);
	node->value = buffer;
	free(buffer);
}

int	main(int argc, char **argv, char **envp)
{
	// minishell(envp);

	char	*line;
	int		status;
	t_node	*node;

	while (status != -1)
	{
		signal_handler(0);
		ft_readline(node);
		if (ft_strncmp(node->value, "exit", 4) == 0)
			status = -1;
		if (line == NULL)
			break ;
	}
	
	return (0);
}

// "ls -l | grep .txt > output.txt"
// ls - compare - found - settype - 
// 
// 