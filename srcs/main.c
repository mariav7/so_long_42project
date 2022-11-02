/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/02 16:03:05 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	printf("Coucou moda foca \n");

	void	*mlx_ptr;

	if (!(mlx_ptr = mlx_init()))
    {
      printf(" !! KO !!\n");
      exit(1);
    }

	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	mlx_ptr = NULL;

	return (0);
}
