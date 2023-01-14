/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:29:38 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/14 17:11:59 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	cmp;
	size_t	li;

	li = ft_strlen(little);
	cmp = 0;
	i = 0;
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && (i + li <= len))
	{
		cmp = ft_strncmp(&big[i], little, li);
		if (!cmp)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
