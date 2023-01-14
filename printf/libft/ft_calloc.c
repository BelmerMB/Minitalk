/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 18:13:38 by emetras-          #+#    #+#             */
/*   Updated: 2022/06/16 22:38:22 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	max = nmemb * size;
	if (nmemb <= 0 || size <= 0 || ((max / size) != nmemb))
		return (NULL);
	ptr = malloc(max);
	if (ptr == NULL)
		return (NULL);
	return (ft_memset(ptr, 0, max));
}
