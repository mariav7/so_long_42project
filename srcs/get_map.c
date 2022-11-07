/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:03 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/07 18:02:58 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**get_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		error_message_n_exit(ERR_FILE2);
	while (line)
	{
		line = get_next_line(fd);
        //printf("%s", line);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = ft_strjoin(all_lines, line);
        //printf("%s", all_lines);
		free(line);
        //printf("%s", line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		basic_error_message(ERR_FILE3);
	return (ft_split(all_lines, '\n'));
}