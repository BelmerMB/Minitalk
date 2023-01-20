/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:51:52 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/20 12:19:32 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include <signal.h>

void    sig_handler(int signal)
{
    if(signal == SIGUSR1)
        printf("voce mando sinal SIGUSR1\n");

    if(signal == SIGUSR2)
        printf("voce mando sinal SIGUSR2\n");

}

int main (void)
{
    struct sigaction	sa_signal;

    sa_signal.sa_handler = 0;
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}