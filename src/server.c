/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:48:22 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/16 11:01:52 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

int main(void)
{
	//signal(SIGUSR1, &sig_handler);
	//signal(SIGUSR2, &sig_handler);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
}

// void	sig_handler()
// {
	
// }
