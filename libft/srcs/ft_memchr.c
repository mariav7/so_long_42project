/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:46:36 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:03:22 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Scans the initial 'n' bytes of the memory area pointed to by 's' for the 
	first instance of 'c'
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cast_s;
	size_t			i;

	if (!s)
		return (NULL);
	cast_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cast_s[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
