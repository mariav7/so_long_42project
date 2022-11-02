/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:12:21 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:05:24 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	If 'c' is an uppercase letter, the function returns its 
	lowercase equivalent otherwise it returns 'c'.
*/

int	ft_tolower(char c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
