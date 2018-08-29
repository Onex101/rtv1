/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:23:52 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/29 18:04:24 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

void	matrix_cpy(t_mat *source, t_mat *dest)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest->mat[i][j] = source->mat[i][j];
			j++;
		}
		i++;
	}
}

t_mat	*matrix_mult(t_mat *mat1, t_mat *mat2)
{
	int		i;
	int		j;
	t_mat	*ret;

	i = 0;
	ret = (t_mat *)malloc(sizeof(t_mat));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ret->mat[i][j] = mat1->mat[i][0] * mat2->mat[0][j] +
								mat1->mat[i][1] * mat2->mat[1][j] +
								mat1->mat[i][2] * mat2->mat[2][j] +
								mat1->mat[i][3] * mat2->mat[3][j];
			j++;
		}
		i++;
	}
	return (ret);
}

t_vec3	*matrix_vec_mult(t_vec3 *source, t_mat *mat)
{
	t_vec3 *dest;

	dest = (t_vec3 *)malloc(sizeof(t_vec3));
	dest->x = source->x * mat->mat[0][0] +
				source->y * mat->mat[1][0] +
				source->z * mat->mat[2][0] +
							mat->mat[3][0];
	dest->y = source->x * mat->mat[0][1] +
				source->y * mat->mat[1][1] +
				source->z * mat->mat[2][1] +
							mat->mat[3][1];
	dest->z = source->x * mat->mat[0][2] +
				source->y * mat->mat[1][2] +
				source->z * mat->mat[2][2] +
							mat->mat[3][2];
	return (dest);
}

void	matrix_identity(t_mat *mat)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat->mat[i][j] = 1;
			else
				mat->mat[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_mat	*matrix_master(t_vec3 *scale, t_vec3 *translate, t_vec3 *rotate)
{
	t_mat		*s;
	t_mat		*t;
	t_mat		*r;
	t_mat		*m;
	t_mat		*tmp;

	s = matrix_scale(scale);
	t = matrix_translate(translate);
	r = matrix_rotate(rotate);
	tmp = matrix_mult(r, t);
	m = matrix_mult(tmp, s);
	free(s);
	free(t);
	free(r);
	free(tmp);
	return (m);
}
