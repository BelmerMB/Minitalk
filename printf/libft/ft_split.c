/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:00:35 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/24 18:42:12 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_world(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	ft_size_str(const char *str, char c)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (str[index])
	{
		if (str[index] != c)
		{
			count++;
			while (str[index] != c && str[index])
				index++;
		}
		else
			index++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ptr_array;
	int		aux;
	int		size_w;

	size_w = 0;
	aux = 0;
	if (!s)
		return (0);
	count = ft_size_str(s, c);
	ptr_array = (char **) ft_calloc((count +1), sizeof(char *));
	if (!ptr_array)
		return (NULL);
	while (aux < count)
	{
		while (*s == c && *s)
			s++;
		size_w = ft_size_world(s, c);
		ptr_array[aux] = ft_substr(s, 0, size_w);
		s += size_w + 1;
		aux++;
	}
	return (ptr_array);
}
