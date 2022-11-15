/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:02:03 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/15 09:36:18 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

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

void	get_map(t_data *m, char *fmap)
{
	char	*line;
	char	*all_lines;
	int		fd;

	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		error_message_n_exit(ERR_FILE2, m);
	line = "";
	all_lines = ft_strdup("");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_lines = string_join(all_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		error_exit(m, ERR_FILE3, all_lines);
	m->map->map = ft_split(all_lines, '\n');
	m->map->tmp_map = ft_split(all_lines, '\n');
	free(all_lines);
}