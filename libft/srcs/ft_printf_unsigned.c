/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:48:55 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:03:57 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printbase_u(unsigned int nbr, int base, const char *hexa)
{
	int		len;

	len = 0;
	if (nbr >= (unsigned int)base)
		len += ft_printbase_u(nbr / base, base, hexa);
	len += ft_printchar(hexa[nbr % base]);
	return (len);
}

int	ft_printptr_u(unsigned long nbr, int base, const char *hexa)
{
	int		len;

	len = 0;
	if (nbr == 0)
	{
		len += ft_printstr(NIL_PTR);
		return (len);
	}
	else
		len += ft_printstr("0x") + ft_putptr_u(nbr, base, hexa);
	return (len);
}

int	ft_putptr_u(unsigned long nbr, int base, const char *hexa)
{
	int		len;

	len = 0;
	if (nbr >= (unsigned long)base)
		len += ft_putptr_u(nbr / base, base, hexa);
	len += ft_printchar(hexa[nbr % base]);
	return (len);
}
