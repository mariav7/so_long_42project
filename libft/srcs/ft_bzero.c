/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:06:34 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:02:01 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Erases the data in the 'n' bytes of the memory starting at the location
	pointed to by 's' by writing zeros '\0' to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	if (!s)
		return ;
	ptr = (char *) s;
	while (n > 0)
	{
		*ptr = '\0';
		ptr++;
		n--;
	}
}
