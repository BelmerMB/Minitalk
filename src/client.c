/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:51:58 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/20 12:21:43 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int		send_char(int pid, char *str);
int		send_null(int pid, char *str);
void	sig_handler (int sig);
void	error_handle(char *str);

int	main (int argc, char **argv)
{
	if ((argc != 3) || (ft_atoi(argv[1]) == 0))
	{
		ft_printf("Error: Wrong number of arguments\n");
		ft_printf("Try  : [server PID] \"message\"\n");
		exit(1);
	}
	signal(SIGUSR1, &sig_handler);
	signal(SIGUSR2, &sig_handler);
	send_char(ft_atoi(argv[1]), argv[2]);
	while(1)
		pause();
}

int	send_char(int pid, char *str)
{
	static char	*message = 0;
	static int	s_pid = 0;
	static int	bits = -1;

	if (str)
		message = ft_strdup(str);
	if (!message)
		error_handle(0);
	if (pid)
		s_pid = pid;
	if (message[++bits / 8])
	{
		if (message[bits / 8] & (128 >> (bits % 8)))
		{
			if (kill(s_pid, SIGUSR2) == -1)
				error_handle(message);
		}
		else if (kill(s_pid, SIGUSR1) == -1)
			error_handle(message);
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	return (1);
}

void	sig_handler (int sig)
{
	int	end_str;

	end_str = 0;
	if (sig == SIGUSR1)
		end_str = send_char(0, 0);
	else if (sig == SIGUSR2)
	{
		ft_printf("Server ended unexpectdly.\n");
		exit(EXIT_FAILURE);
	}
	if (end_str)
	{
		ft_printf("Operation successful.\n");
		exit(EXIT_SUCCESS);
	}
}

void	error_handle(char *str)
{
	if (str)
		free(str);
	ft_printf("Error: try again and check serve PID\n");
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *str)
{
	static int	i = 0;

	if (i++ != 8)
	{
		if (kill(pid, SIGUSR1) == -1)
			error_handle(str);
		return (0);
	}
	return (1);
}
