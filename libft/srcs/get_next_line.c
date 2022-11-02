/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:42:30 by mflores-          #+#    #+#             */
/*   Updated: 2022/06/16 19:13:24 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Retourne une ligne lue depuis un descripteur de fichier
	Compilation:
		cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 file.c
*/

/* 		1024 is the number of file descriptors a process can open on an 
		UNIX based operating system 
		Command : ulimit -n 
*/

char	*gnl_read_file(int fd, char *stash)
{
	int		bytes_rd;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	bytes_rd = 1;
	while (bytes_rd > 0)
	{
		bytes_rd = read(fd, buff, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_rd] = '\0';
		stash = gnl_free(stash, buff);
		if (gnl_strchr(stash, '\n'))
			break ;
	}
	free(buff);
	return (stash);
}

char	*gnl_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*gnl_update_stash(char *old_stash)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (old_stash[i] && old_stash[i] != '\n')
		i++;
	if (!old_stash[i])
	{
		free(old_stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (gnl_strlen(old_stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (old_stash[i])
		new_stash[j++] = old_stash[i++];
	new_stash[j] = '\0';
	free(old_stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024 || read(fd, 0, 0) < 0)
		return (NULL);
	stash[fd] = gnl_read_file(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = gnl_get_line(stash[fd]);
	stash[fd] = gnl_update_stash(stash[fd]);
	return (line);
}
