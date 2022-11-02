/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:43:03 by mflores-          #+#    #+#             */
/*   Updated: 2022/06/16 15:46:01 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*gnl_free(char *stash, char *buff)
{
	char	*temp;

	if (!stash)
	{
		stash = (char *)malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	temp = gnl_strjoin(stash, buff);
	free(stash);
	return (temp);
}

char	*gnl_strjoin(char *stash, char *buffer)
{
	char	*new_str;
	size_t	i;
	size_t	x;

	if (!stash || !buffer)
		return (NULL);
	new_str = malloc(sizeof(char) * gnl_strlen(stash) + gnl_strlen(buffer) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	x = 0;
	while (stash[i])
		new_str[x++] = stash[i++];
	i = 0;
	while (buffer[i])
		new_str[x++] = buffer[i++];
	new_str[x] = '\0';
	return (new_str);
}
