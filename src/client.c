/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:51:58 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/13 23:56:12 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int	main (int argc, char **argv)
{
	unsigned int	pid;

	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	if ((argc == 3) && (pid > 0))
		send_message(pid, argv[2]);
	else
	{
		ft_printf("Error: Wrong number of arguments\n");
		return (0);
	}
	return (0);
}

