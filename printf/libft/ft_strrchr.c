/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:15:55 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/03 03:45:22 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;
	int	last;

	last = -1;
	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			last = index;
		index++;
	}
	if (s[index] == (char)c)
		last = index;
	if (last >= 0)
		return ((char *)&s[last]);
	return (NULL);
}
