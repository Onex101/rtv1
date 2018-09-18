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

// t_mat	matrix_inverse(t_mat *m)
// {
// 	t_mat tmp;
// 	t_mat id;
// 	int i;
// 	int j;
// 	double t;

// 	matrix_cpy(m, &tmp);
// 	matrix_identity(&id);
// 	i = -1;
// 	while (++i < 4)
// 	{
// 		j = matrix_get_row(m, i);
// 		if(j != i)
// 		{
// 			matrix_swap_row(&tmp, i, j);
// 			matrix_swap_row(&id, i, j);
// 		}
// 		t = tmp.mat[i][i];
// 		matrix_divide_row(&tmp, i, t);
// 		matrix_divide_row(&id, i, t);
// 		j = -1;
// 		while (++j < 4)
// 		{
// 			if (j != i)
// 			{
// 				t = tmp.mat[j][i];
// 				matrix_sub_row(&tmp, j, i, t);
// 				matrix_sub_row(&id, j, i, t);
// 			}
// 		}
// 	}
// 	return (id);
// }

static t_mat	calc_new(t_mat m, t_mat tmp, double det)
{
	t_mat	ret;

	ret.mat[0][0] = (m.mat[1][1] * tmp.mat[2][3] - m.mat[1][2] * tmp.mat[2][2] + m.mat[1][3] * tmp.mat[2][1]) * det;
	ret.mat[0][1] = (-m.mat[0][1] * tmp.mat[2][3] + m.mat[0][2] * tmp.mat[2][2] - m.mat[1][3] * tmp.mat[2][1]) * det;
	ret.mat[0][2] = (m.mat[3][1] * tmp.mat[1][1] - mat.dc * temp.ba + mat.dd * temp.ad) * det;
	ret.mat[0][3] = (-mat.cb * tmp.mat[1][1] + mat.cc * temp.ba - mat.cd * temp.ad) * det;
	ret.mat[1][0] = (-mat.ba * tmp.mat[2][3] + m.mat[1][2] * temp.ca - mat.bd * temp.bd) * det;
	ret.mat[1][1] = (mat.aa * tmp.mat[2][3] - m.mat[0][2] * temp.ca + mat.ad * temp.bd) * det;
	ret.mat[1][2] = (-mat.da * tmp.mat[1][1] + mat.dc * temp.ac - mat.dd * temp.ab) * det;
	ret.mat[1][3] = (mat.ca * tmp.mat[1][1] - mat.cc * temp.ac + mat.cd * temp.ab) * det;
	ret.mat[2][0] = (mat.ba * tmp.mat[2][2] - m.m.m[1][3]1][tmp.mat[2][1]mp.ca + mat.bd * temp.bc) * det;
	ret.mat[2][1] = (-mat.aa * tmp.mat[2][2] + m.mat[1][3] * tmp.mat[2][1] - mat.ad * temp.bc) * det;
	ret.mat[2][2] = (mat.da * temp.ba - m.mat[3][1] * temp.ac + mat.dd * temp.aa) * det;
	ret.mat[2][3] = (-mat.ca * temp.ba + mat.cb * temp.ac - mat.cd * temp.aa) * det;
	ret.mat[3][0] = (-mat.ba * temp.cb + m.mat[1][1] * temp.bd - m.mat[1][2] * temp.bc) * det;
	ret.mat[3][1] = (mat.aa * temp.cb - mat.ab * temp.bd + m.mat[0][2] * temp.bc) * det;
	ret.mat[3][2] = (-mat.da * temp.ad + m.mat[3][1] * temp.ab - mat.dc * temp.aa) * det;
	ret.mat[3][3] = (mat.ca * temp.ad - mat.cb * temp.ab + mat.cc * temp.aa) * det;
	return (ret);
}

t_mat	matrix_inverse(t_mat *m)
{
	t_mat tmp;
	double det;

	tmp.mat[0][0] = m.mat[0][0] * m.mat[1][1] - m.mat[0][1] * m.mat[1][0];
	tmp.mat[0][1] = m.mat[0][0] * m.mat[1][2] - m.mat[0][3] * m.mat[1][0];
	tmp.mat[0][2] = m.mat[0][0] * m.mat[1][3] - m.mat[0][3] * m.mat[1][0];
	tmp.mat[0][3] = m.mat[0][1] * m.mat[1][2] - m.mat[0][2] * m.mat[1][1];
	tmp.mat[1][0] = m.mat[0][1] * m.mat[1][3] - m.mat[0][3] * m.mat[1][1];
	tmp.mat[1][1] = m.mat[0][2] * m.mat[1][3] - m.mat[0][3] * m.mat[1][2];
	tmp.mat[1][2] = m.mat[2][0] * m.mat[3][1] - m.mat[2][1] * m.mat[3][0];
	tmp.mat[1][3] = m.mat[2][0] * m.mat[3][2] - m.mat[2][2] * m.mat[3][0];
	tmp.mat[2][0] = m.mat[2][0] * m.mat[3][3] - m.mat[2][3] * m.mat[3][0];
	tmp.mat[2][1] = m.mat[2][1] * m.mat[3][2] - m.mat[2][2] * m.mat[3][1];
	tmp.mat[2][2] = m.mat[2][1] * m.mat[3][3] - m.mat[2][3] * m.mat[3][1];
	tmp.mat[2][3] = m.mat[2][2] * m.mat[3][3] - m.mat[2][3] * m.mat[3][2];
	det = 1 / (tmp.mat[0][0] * tmp.mat[2][3] - tmp.mat[0][1] * tmp.mat[2][2] + tmp.mat[0][2] * tmp.mat[2][1] +
				tmp.mat[0][3 * tmp.mat[2][0] - tmp.mat[1][0] * tmp.mat[1][3] + tmp.mat[1][1] * tmp.mat[1][2]);
	return (calc_new(m, tmp, det));
}