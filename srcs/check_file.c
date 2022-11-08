/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:36:07 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/08 19:50:45 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	find_extension(char *file, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != file[i])
			return (0);
		i++;
	}
	if (file[i] == '\0')
		return (1);
	return (0);
}

void	check_file(char *file)
{
	while (*file)
	{
		if (*file == '.')
		{
			if (find_extension(file, ".ber"))
				return ;
		}
		file++;
	}
	basic_error_message(ERR_FILE, NULL);
}