/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:12:40 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:05:27 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	If 'c' is a lowercase letter, the function returns its 
	uppercase equivalent otherwise it returns 'c'.
*/

int	ft_toupper(char c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}
