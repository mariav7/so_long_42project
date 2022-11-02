/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:38:57 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:05:12 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Locates the first occurrence of the null-terminated string little in the 
	string 'big', where not more than 'len' characters are searched.
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	if (!little[0])
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		x = 0;
		while (big[i + x] && little[x]
			&& i + x < len && big[i + x] == little[x])
			x++;
		if (!little[x])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
