/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:26:52 by emetras-          #+#    #+#             */
/*   Updated: 2022/08/15 12:38:40 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intsz(int b)
{
	int	sz;

	sz = 0;
	while (b)
	{
		b = b / 10;
		sz++;
	}
	return (sz);
}

static void	ft_intascii(int size, char *ptr, unsigned int aux)
{
	while (size-- >= 1)
	{
		ptr[size] = (aux % 10) + '0';
		aux = aux / 10;
	}
}

char	*ft_itoa(int n)
{
	char				*ptr;
	int					size;
	int					signal;
	unsigned int		aux;

	size = 1;
	signal = 0;
	if (!n)
		size = 2;
	if (n < 0 && size++)
	{
		aux = n * -1;
		signal = 1;
	}
	else
		aux = n;
	size += ft_intsz (aux);
	ptr = (char *) ft_calloc(size, sizeof (char));
	if (!ptr)
		return (NULL);
	ptr[--size] = '\0';
	ft_intascii (size, ptr, aux);
	if (signal)
		ptr[0] = '-';
	return (ptr);
}
