/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:35:49 by emetras-          #+#    #+#             */
/*   Updated: 2022/12/15 11:36:15 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		var;
	int		signal;

	i = 0;
	var = 0;
	signal = 0;
	while (ft_isspace(nptr[i]) && nptr[i] != '\0')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		signal = i++;
	while (ft_isdigit(nptr[i]))
	{
		var *= 10;
		var += nptr[i] - 48;
		i++;
	}
	if (nptr[signal] == '-')
		return (var * -1);
	else if (var)
		return (var);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	else if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}
