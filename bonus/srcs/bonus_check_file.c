/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_check_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:36:07 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/14 15:20:07 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

static int	find_extension(char *file, char *file_type)
{
	int	i;

	i = 0;
	while (file_type[i])
	{
		if (file_type[i] != file[i])
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
			if (find_extension(file, FILE_TYPE))
				return ;
		}
		file++;
	}
	basic_error_message(ERR_FILE, NULL);
}
