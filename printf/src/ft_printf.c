/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:12:20 by emetras-          #+#    #+#             */
/*   Updated: 2022/08/02 13:12:20 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_printf.h"

static int	ft_arguments(const char	*c, va_list	doguinho);

int	ft_printf(const char *format, ...)
{
	va_list	dog;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(dog, format);
	while (format[i])
	{
		if (format[i] != '%')
			count += write(1, &format[i], 1);
		else
		{
			i++;
			count += ft_arguments(&format[i], dog);
		}
		i++;
	}
	return (count);
}

static int	ft_arguments(const char *c, va_list doguinho)
{
	int	ax;

	if (*c == '%')
		return (write(1, c, 1));
	if (*c == 'c')
	{
		ax = va_arg(doguinho, int);
		return (write(1, &ax, 1));
	}
	if (*c == 's')
		return (ft_print_str(doguinho));
	if (*c == 'd' || *c == 'i')
		return (ft_print_dec(doguinho));
	if (*c == 'u')
		return (ft_print_unsigned(va_arg(doguinho, unsigned int)));
	if (*c == 'x')
		return (ft_print_hex(va_arg(doguinho, unsigned int), 'a'));
	if (*c == 'X')
		return (ft_print_hex(va_arg(doguinho, unsigned int), 'A'));
	if (*c == 'p')
		return (ft_print_ptr(va_arg(doguinho, unsigned long int)));
	else
		return (write(1, "%", 1), write(1, c, 1), 2);
}
