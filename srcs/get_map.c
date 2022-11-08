/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:03 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/08 11:18:05 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	printf("height: %d\n", i);
	return (i);
}

static char	*string_join(char *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1_s2;
	size_t	i;
	size_t	x;

	if (!s1)
		s1 = ft_strdup("");
	len_s1_s2 = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_str = malloc(sizeof(char) * len_s1_s2);
	if (!new_str)
		return (NULL);
	i = 0;
	x = 0;
	while (s1[i])
		new_str[x++] = s1[i++];
	i = 0;
	while (s2[i])
		new_str[x++] = s2[i++];
	new_str[x] = 0;
	free(s1);
	return (new_str);
}

char	**get_map(char *fmap)
{
	char	*line;
	char	*all_lines;
	char	**map;
	int		fd;

	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		error_message_n_exit(ERR_FILE2);
	line = "";
	all_lines = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		all_lines = string_join(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		basic_error_message(ERR_FILE3, (void *)all_lines);
	map = ft_split(all_lines, '\n');
	free(all_lines);
	return (map);
}
