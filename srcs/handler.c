/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:58:32 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/14 20:09:00 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	signal_handler(int num)
{
	if (num == 0)
	{
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	// else if (num == 1)
	// {
	// 	signal(SIGINT, quitsubshell);
	// 	signal(SIGQUIT, quit3);
	// }
}

// void sig_handler(int signum) {
//     if (signum == SIGINT) {
//         // Print a newline and reset the readline state
//         write(STDOUT_FILENO, "\n", 1);
//         rl_on_new_line();
//         rl_replace_line("", 0);
//         rl_redisplay();
//         // printf("CTRL-C\n");
//     }
//     else if (signum == SIGQUIT) {
//         printf("Quit: 3");
//     }
// }
