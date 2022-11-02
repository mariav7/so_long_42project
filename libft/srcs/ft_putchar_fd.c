/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:42:19 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:04:09 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Ecrit le caractere 'c' sur le descripteur de fichier donne
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
