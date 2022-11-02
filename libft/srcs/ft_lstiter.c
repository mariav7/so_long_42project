/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:47:15 by mflores-          #+#    #+#             */
/*   Updated: 2022/08/12 15:03:06 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Itere sur la liste 'lst' et applique la fonction 'f' au contenu
	chaque element
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst && f)
	{
		while (lst)
		{
			temp = lst->next;
			f(lst->content);
			lst = temp;
		}
	}
}
