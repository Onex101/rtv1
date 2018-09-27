/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:52:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:15:39 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lib_mat.h"

void	matrix_print(t_mat *m)
{
	int i;
	int j;

	if (m)
	{
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				ft_putnbr(m->mat[i][j]);
			ft_putstr("\n");
		}
	}
}
