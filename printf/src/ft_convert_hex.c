/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:26:31 by emetras-          #+#    #+#             */
/*   Updated: 2023/01/02 20:25:10 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static unsigned long int	ft_size_nbr(unsigned long int nbr);
static unsigned long int	ft_print(char *nbr_in_hexa);

int	ft_print_hex(unsigned long int nbr, char upcase)
{
	unsigned long int	size_nbr;
	char				*nbr_in_hexa;

	size_nbr = ft_size_nbr(nbr);
	if (!size_nbr)
		return (ft_print("0"));
	nbr_in_hexa = (char *) malloc((size_nbr * sizeof(char)) + 1);
	if (!nbr_in_hexa)
		return (0);
	nbr_in_hexa[size_nbr] = '\0';
	while (nbr)
	{
		size_nbr--;
		nbr_in_hexa[size_nbr] = (nbr % 16) + '0';
		if (nbr_in_hexa[size_nbr] > '9')
		{
			nbr_in_hexa[size_nbr] = (nbr_in_hexa[size_nbr] - 58) + upcase;
		}
		nbr = nbr / 16;
	}
	size_nbr = ft_print(nbr_in_hexa);
	free (nbr_in_hexa);
	return (size_nbr);
}

static unsigned long int	ft_size_nbr(unsigned long int nbr)
{
	unsigned long int	size;

	size = 0;
	while (nbr)
	{
		size++;
		nbr = nbr / 16;
	}
	return (size);
}

static unsigned long int	ft_print(char *nbr_in_hexa)
{
	unsigned long int	size;

	size = 0;
	while (nbr_in_hexa[size])
	{
		size++;
	}
	return (write(1, nbr_in_hexa, size));
}
