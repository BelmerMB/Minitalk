/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 19:57:39 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/02 20:28:29 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

int	ft_print_ptr(unsigned long int nbr)
{
	if (!nbr)
	{
		return (write(1, "(nil)", 5));
	}
	write(1, "0x", 2);
	return (ft_print_hex(nbr, 'a') + 2);
}
