/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:06:47 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:03:26 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Compares the first 'n' bytes of the memory areas 's1' and 's2'.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;
	size_t			pos;

	pos = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (pos < n)
	{
		if (ptr_s1[pos] != ptr_s2[pos])
			return (ptr_s1[pos] - ptr_s2[pos]);
		pos++;
	}
	return (0);
}
