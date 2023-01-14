/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emetras- <emetras-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:19:02 by emetras-          #+#    #+#             */
/*   Updated: 2022/08/02 13:19:02 by emetras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *c, ...);
int	ft_print_str(va_list list);
int	ft_print_dec(va_list list);
int	ft_print_hex(unsigned long int number, char upcase);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_ptr(unsigned long int nbr);

#endif