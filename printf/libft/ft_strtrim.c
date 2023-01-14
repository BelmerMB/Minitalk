/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:21:08 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/21 18:58:24 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	size;

	start = 0;
	size = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	size = ft_strlen(&s1[start]);
	if (size > 0)
		while (s1[start + size - 1] && ft_strrchr(set, s1[start + size - 1]))
			size--;
	return (ft_substr(s1, start, size));
}
