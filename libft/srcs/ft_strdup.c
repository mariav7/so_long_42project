/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:36:43 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:04:27 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns a pointer to a new string which is a duplicate of the string 's'
*/

char	*ft_strdup(const char *s)
{
	char	*str;
	int		src_len;
	int		i;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	str = malloc(sizeof(char) * (src_len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
