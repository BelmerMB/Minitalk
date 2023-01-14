/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:51:26 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/12 23:41:42 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	length;

	length = ft_strlen(dst);
	if (size < length)
		return (ft_strlen(src) + size);
	ft_strlcpy (&dst[length], src, size - length);
	return (ft_strlen(src) + length);
}
