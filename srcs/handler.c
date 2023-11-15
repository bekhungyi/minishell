/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:58:32 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/11/15 23:17:53 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	quit3(int sig)
{
	(void)sig;
	write(1, "Quit: 3\n", 9);
}

void	quitsubshell(int sig)
{
	(void)sig;
	printf("\n");
}

void	sigint_handler(int sig)
{
	(void)sig;
	printf("\n");
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
	else if (num == 1)
	{
		signal(SIGINT, quitsubshell);
		signal(SIGQUIT, quit3);
	}
}
