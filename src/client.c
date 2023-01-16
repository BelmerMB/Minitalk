/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:51:58 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/16 10:32:25 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

void	send_message(int pid, char *msg);
void	send_char(int pid, char c);

int	main (int argc, char **argv)
{
	unsigned int	pid;

	if ((argc == 3) && (ft_atoi(argv[1]) > 0))
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	return (0);
}

void	send_message(int pid, char *msg)
{
	int index;

	while (msg[index] != '\0')
	{
		send_char(pid, msg[index]);
		//usleep(100);
		index++;
	}
	send_char(pid, msg[index]);
}

void	send_char(int pid, char c)
{
	int index;

	index = 0;
	while (index < 8)
	{
		if ((c >> index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		index++;
		usleep(100);
	}
}