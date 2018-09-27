/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:19:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 19:33:20 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_exit(t_param *p)
{
	exit_program(p);
	return (0);
}

void	arg_check(char *str, t_param *p)
{
	if (!(ft_rt(str)))
	{
		ft_putendl("Error: Invalid File Type");
		exit_program(p);
	}
	if (!(read_file(str, p)))
	{
		ft_putendl("Error: Invalid File Read");
		exit_program(p);
	}
}

void	start_mlx(t_param *p)
{
	if (OS)
		mlx_hook(p->win, 2, 0, key_press, p);
	else
		mlx_hook(p->win, 2, 1, key_press, p);
	mlx_hook(p->win, 17, 0, ft_exit, p);
	mlx_loop_hook(p->mlx, render, p);
	mlx_loop(p->mlx);
}

int		main(int argc, char **argv)
{
	t_param *p;

	if (argc == 2)
	{
		p = (t_param *)malloc(sizeof(t_param));
		if (init_param(p))
		{
			arg_check(argv[1], p);
			start_mlx(p);
		}
		else
		{
			ft_putendl("Error: Failed to Initialize Parameters");
			exit_program(p);
		}
	}
	else
	{
		ft_putendl("Error: Incorrect Number of Arguments");
		return (1);
	}
	return (0);
}
