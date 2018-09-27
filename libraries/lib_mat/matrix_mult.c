/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:00:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:11:44 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_mat	matrix_mult(t_mat mat1, t_mat mat2)
{
	int		i;
	int		j;
	t_mat	ret;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret.mat[i][j] = mat1.mat[i][0] * mat2.mat[0][j] +
							mat1.mat[i][1] * mat2.mat[1][j] +
							mat1.mat[i][2] * mat2.mat[2][j] +
							mat1.mat[i][3] * mat2.mat[3][j];
			j++;
		}
		i++;
	}
	return (ret);
}
