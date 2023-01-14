/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 05:24:34 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/18 06:12:06 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	size_t	index;
	char	*ptr;

	index = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *) ft_calloc(size +1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[index++] = *s1++;
	while (*s2)
		ptr[index++] = *s2++;
	ptr[index] = '\0';
	return (ptr);
}
