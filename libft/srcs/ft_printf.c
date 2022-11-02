/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:39:31 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:04:03 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_arg(const char *format, int i, va_list args)
{
	int	len;

	len = 0;
	if (format[i] == '%')
		len = ft_printchar(format[i]);
	else if (format[i] == 'c')
		len = ft_printchar(va_arg(args, int));
	else if (format[i] == 's')
		len = ft_printstr(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		len = ft_printnbr(va_arg(args, int));
	else if (format[i] == 'u')
		len = ft_printbase_u(va_arg(args, unsigned int), 10, BASE_DEC);
	else if (format[i] == 'x')
		len = ft_printbase_u(va_arg(args, unsigned int), 16, HEXA_MIN);
	else if (format[i] == 'X' )
			len = ft_printbase_u(va_arg(args, unsigned int), 16, HEXA_MAJ);
	else if (format[i] == 'p')
		len = ft_printptr_u(va_arg(args, unsigned long), 16, HEXA_MIN);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr(CONV, format[i + 1]))
		{
			len += ft_print_arg(format, i + 1, args);
			i++;
		}
		else
			len += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
