/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:47:17 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:51:44 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

static void		calc_new_c(t_mat *ret, t_mat *m, t_mat tmp, double det)
{
	ret->mat[2][0] = (m->mat[1][0] * tmp.mat[2][2] - m->mat[1][1] *
					tmp.mat[2][1] + m->mat[1][3] * tmp.mat[1][2]) * det;
	ret->mat[2][1] = (-m->mat[0][0] * tmp.mat[2][2] + m->mat[1][3] *
					tmp.mat[2][1] - m->mat[0][3] * tmp.mat[1][2]) * det;
	ret->mat[2][2] = (m->mat[3][0] * tmp.mat[1][0] - m->mat[3][1] *
					tmp.mat[0][2] + m->mat[3][3] * tmp.mat[0][0]) * det;
	ret->mat[2][3] = (-m->mat[2][0] * tmp.mat[1][0] + m->mat[2][1] *
					tmp.mat[0][2] - m->mat[2][3] * tmp.mat[0][0]) * det;
	ret->mat[3][0] = (-m->mat[1][0] * tmp.mat[2][1] + m->mat[1][1] *
					tmp.mat[1][3] - m->mat[1][2] * tmp.mat[1][2]) * det;
	ret->mat[3][1] = (m->mat[0][0] * tmp.mat[2][1] - m->mat[0][1] *
					tmp.mat[1][3] + m->mat[0][2] * tmp.mat[1][2]) * det;
	ret->mat[3][2] = (-m->mat[3][0] * tmp.mat[0][3] + m->mat[3][1] *
					tmp.mat[0][1] - m->mat[3][2] * tmp.mat[0][0]) * det;
	ret->mat[3][3] = (m->mat[2][0] * tmp.mat[0][3] - m->mat[2][1] *
					tmp.mat[0][1] + m->mat[2][2] * tmp.mat[0][0]) * det;
}

static t_mat	calc_new(t_mat *m, t_mat tmp, double det)
{
	t_mat	ret;

	ret.mat[0][0] = (m->mat[1][1] * tmp.mat[2][3] - m->mat[1][2] *
					tmp.mat[2][2] + m->mat[1][3] * tmp.mat[2][1]) * det;
	ret.mat[0][1] = (-m->mat[0][1] * tmp.mat[2][3] + m->mat[0][2] *
					tmp.mat[2][2] - m->mat[1][3] * tmp.mat[2][1]) * det;
	ret.mat[0][2] = (m->mat[3][1] * tmp.mat[1][1] - m->mat[3][2] *
					tmp.mat[1][0] + m->mat[3][3] * tmp.mat[0][3]) * det;
	ret.mat[0][3] = (-m->mat[2][1] * tmp.mat[1][1] + m->mat[2][2] *
					tmp.mat[1][0] - m->mat[2][3] * tmp.mat[0][3]) * det;
	ret.mat[1][0] = (-m->mat[1][0] * tmp.mat[2][3] + m->mat[1][2] *
					tmp.mat[2][0] - m->mat[1][3] * tmp.mat[1][3]) * det;
	ret.mat[1][1] = (m->mat[0][0] * tmp.mat[2][3] - m->mat[0][2] *
					tmp.mat[2][0] + m->mat[0][3] * tmp.mat[1][3]) * det;
	ret.mat[1][2] = (-m->mat[3][0] * tmp.mat[1][1] + m->mat[3][2] *
					tmp.mat[0][2] - m->mat[3][3] * tmp.mat[0][1]) * det;
	ret.mat[1][3] = (m->mat[2][0] * tmp.mat[1][1] - m->mat[2][2] *
					tmp.mat[0][2] + m->mat[2][3] * tmp.mat[0][1]) * det;
	calc_new_c(&ret, m, tmp, det);
	return (ret);
}

t_mat			matrix_inverse(t_mat *m)
{
	t_mat	tmp;
	double	det;

	tmp.mat[0][0] = m->mat[0][0] * m->mat[1][1] - m->mat[0][1] * m->mat[1][0];
	tmp.mat[0][1] = m->mat[0][0] * m->mat[1][2] - m->mat[0][3] * m->mat[1][0];
	tmp.mat[0][2] = m->mat[0][0] * m->mat[1][3] - m->mat[0][3] * m->mat[1][0];
	tmp.mat[0][3] = m->mat[0][1] * m->mat[1][2] - m->mat[0][2] * m->mat[1][1];
	tmp.mat[1][0] = m->mat[0][1] * m->mat[1][3] - m->mat[0][3] * m->mat[1][1];
	tmp.mat[1][1] = m->mat[0][2] * m->mat[1][3] - m->mat[0][3] * m->mat[1][2];
	tmp.mat[1][2] = m->mat[2][0] * m->mat[3][1] - m->mat[2][1] * m->mat[3][0];
	tmp.mat[1][3] = m->mat[2][0] * m->mat[3][2] - m->mat[2][2] * m->mat[3][0];
	tmp.mat[2][0] = m->mat[2][0] * m->mat[3][3] - m->mat[2][3] * m->mat[3][0];
	tmp.mat[2][1] = m->mat[2][1] * m->mat[3][2] - m->mat[2][2] * m->mat[3][1];
	tmp.mat[2][2] = m->mat[2][1] * m->mat[3][3] - m->mat[2][3] * m->mat[3][1];
	tmp.mat[2][3] = m->mat[2][2] * m->mat[3][3] - m->mat[2][3] * m->mat[3][2];
	det = 1 / (tmp.mat[0][0] * tmp.mat[2][3] - tmp.mat[0][1] * tmp.mat[2][2]
			+ tmp.mat[0][2] * tmp.mat[2][1] +
				tmp.mat[0][3] * tmp.mat[2][0] - tmp.mat[1][0] * tmp.mat[1][3]
			+ tmp.mat[1][1] * tmp.mat[1][2]);
	return (calc_new(m, tmp, det));
}
