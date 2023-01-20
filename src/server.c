/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:48:22 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/20 11:59:28 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	end_prog(int pid, char *str)
{
	if (str)
		free(str);
	kill(pid, SIGUSR2);
	exit(EXIT_FAILURE);
}

void	handler_sigusr(int signum, siginfo_t *sig_info, void *context)
{
	static char	character = 0xFF;
	static int	bits = 0;
	static int	pid = 0;

	(void)context;
	if (sig_info->si_pid)
		pid = sig_info->si_pid;
	if (signum == SIGUSR1)
		character &= ~(128 >> bits);
	else if (signum == SIGUSR2)
		character |= 128 >> bits;
	if (++bits == 8)
	{
		if (character)
			ft_printf("%c", character);
		else
			ft_printf("\n");
		bits = 0;
		character = 0xFF;
	}
	if (kill(pid, SIGUSR1) == -1)
		end_prog(pid, &character);
}

int	main(void)
{
	struct sigaction	sa_signal;

	sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = handler_sigusr;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	
	ft_printf("Pid: %d\n",getpid());
	while (1)
		pause();
}