/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:23:21 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/12 23:42:07 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy( void *dest, const void *src, size_t count )
{
	unsigned char	*source;
	unsigned char	*des;
	size_t			i;

	i = 0;
	source = (unsigned char *) src;
	des = (unsigned char *)dest;
	while (i < count)
	{
		des[i] = source [i];
		i++;
	}
	return ((void *) des);
}
