/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:10:39 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:03:54 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Fills the first 'n' bytes of the memory area pointed to by 's' with the
	constant byte 'c'.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	if (!s)
		return (NULL);
	ptr = (char *) s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
