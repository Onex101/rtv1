/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:49:09 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/11 18:25:18 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_mat	matrix_inverse(t_mat *m)
{
	t_mat tmp;
	t_mat id;
	int i;
	int j;
	double t;

	matrix_cpy(m, &tmp);
	matrix_identity(&id);
	i = -1;
	while (++i < 4)
	{
		j = matrix_get_row(m, i);
		if(j != i)
		{
			matrix_swap_row(&tmp, i, j);
			matrix_swap_row(&id, i, j);
		}
		t = tmp.mat[i][i];
		matrix_divide_row(&tmp, i, t);
		matrix_divide_row(&id, i, t);
		j = -1;
		while (++j < 4)
		{
			if (j != i)
			{
				t = tmp.mat[j][i];
				matrix_sub_row(&tmp, j, i, t);
				matrix_sub_row(&id, j, i, t);
			}
		}
	}
	return (id);
}