/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/27 16:35:22 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		init_param(t_param *p)
{
	if (!(p->mlx = mlx_init()))
		return (-1);
	if(!(p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "rtv1")))
		return (-1);	
	if (!(p->img = new_image(p->mlx, WIDTH, HEIGHT)))
		return (-1);
	vector_init(p->set);
}

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
	t_param *p;

	if (init_param(p) == -1)
	{
		ft_putendl("Error: Failed to Initialize Parameters");
		exit_pro(p);
	}
	mlx_loop(p->mlx);
	return (0);
}