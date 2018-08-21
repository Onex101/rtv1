/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/21 12:56:00 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int render()
{
	int i;
	int j;

	j = 0;
	while(j < HEIGHT)
	{
		i = 0 ;
		while (i < WIDTH)
		{
			
			i++;
		}
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	void *mlx;
	void *img;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "rtv1");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_loop(mlx);
	return (0);
}