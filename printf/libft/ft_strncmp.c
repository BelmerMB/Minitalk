/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:40:53 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/03 22:02:56 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((n > i) && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if ((const unsigned char) s1[i] != (const unsigned char) s2[i])
			return ((const unsigned char) s1[i] - (const unsigned char) s2[i]);
		i++;
	}
	return (0);
}
