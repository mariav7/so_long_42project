/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mflores- <mflores-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:47:50 by mflores-          #+#    #+#             */
/*   Updated: 2022/11/03 11:41:46 by mflores-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define	WIN1_SX		400
#define	WIN1_SY		400

int	main(void)
{
	ft_printf("Coucou moda foca \n");

	void	*mlx_ptr;
	void	*win1;

	if (!(mlx_ptr = mlx_init()))
	{
		ft_printf(" !! KO !!\n");
		exit(1);
	}

	if (!(win1 = mlx_new_window(mlx_ptr,WIN1_SX,WIN1_SY,"Title1")))
	{
		ft_printf(" !! KO !!\n");
		exit(1);
	}
  ft_printf("OK\n");

  ft_printf(" => Clear Window ...");
  mlx_clear_window(mlx_ptr,win1);
  ft_printf("OK\n");
  sleep(5);

	//mlx_destroy_window(mlx_ptr, win1);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	free(win1);
	mlx_ptr = NULL;
	win1 = NULL;

	return (0);
}
