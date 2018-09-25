/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_axis_rot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:52:57 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:46:54 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

void	calculate2(t_mat *ret, t_mat *mat, t_mat *rot)
{
	ret->mat[2][0] = mat->mat[0][0] * rot->mat[2][0] + mat->mat[2][0] *
					rot->mat[2][1] + mat->mat[2][0] * rot->mat[2][2];
	ret->mat[2][1] = mat->mat[0][1] * rot->mat[2][0] + mat->mat[1][1] *
					rot->mat[2][1] + mat->mat[2][1] * rot->mat[2][2];
	ret->mat[2][2] = mat->mat[0][2] * rot->mat[2][0] + mat->mat[1][2] *
					rot->mat[2][1] + mat->mat[2][2] * rot->mat[2][2];
	ret->mat[2][3] = mat->mat[0][3] * rot->mat[2][0] + mat->mat[1][3] *
					rot->mat[2][1] + mat->mat[2][3] * rot->mat[2][2];
	ret->mat[3][0] = mat->mat[3][0];
	ret->mat[3][1] = mat->mat[3][1];
	ret->mat[3][2] = mat->mat[3][2];
	ret->mat[3][3] = mat->mat[3][3];
}

t_mat	calculate1(t_mat *mat, t_mat *rot)
{
	t_mat ret;

	ret.mat[0][0] = mat->mat[0][0] * rot->mat[0][0] + mat->mat[2][0] *
					rot->mat[0][1] + mat->mat[2][0] * rot->mat[0][2];
	ret.mat[0][1] = mat->mat[0][1] * rot->mat[0][0] + mat->mat[1][1] *
					rot->mat[0][1] + mat->mat[2][1] * rot->mat[0][2];
	ret.mat[0][2] = mat->mat[0][2] * rot->mat[0][0] + mat->mat[1][2] *
					rot->mat[0][1] + mat->mat[2][2] * rot->mat[0][2];
	ret.mat[0][3] = mat->mat[0][3] * rot->mat[0][0] + mat->mat[1][3] *
					rot->mat[0][1] + mat->mat[2][3] * rot->mat[0][2];
	ret.mat[1][0] = mat->mat[0][0] * rot->mat[2][0] + mat->mat[2][0] *
					rot->mat[1][1] + mat->mat[2][1] * rot->mat[1][2];
	ret.mat[1][1] = mat->mat[0][1] * rot->mat[2][0] + mat->mat[1][1] *
					rot->mat[1][1] + mat->mat[2][1] * rot->mat[1][2];
	ret.mat[1][2] = mat->mat[0][2] * rot->mat[2][0] + mat->mat[1][2] *
					rot->mat[1][1] + mat->mat[2][2] * rot->mat[1][2];
	ret.mat[1][3] = mat->mat[0][3] * rot->mat[2][0] + mat->mat[1][3] *
					rot->mat[1][1] + mat->mat[2][3] * rot->mat[1][2];
	return (ret);
}

t_mat	matrix_axis_rot(t_vec3 axis, double angle)
{
	double	s;
	double	c;
	double	t;
	t_mat	rot;
	t_mat	tmp;

	matrix_identity(&rot);
	matrix_identity(&tmp);
	if (!(vec3_len(axis)) || !angle)
		return (rot);
	vec3_nor(&axis);
	s = sin(angle);
	c = cos(angle);
	t = 1 - c;
	rot.mat[0][0] = axis.x * axis.x * t + c;
	rot.mat[0][1] = axis.y * axis.x * t + axis.z * s;
	rot.mat[0][2] = axis.z * axis.x * t - axis.y * s;
	rot.mat[1][0] = axis.x * axis.y * t - axis.z * s;
	rot.mat[1][1] = axis.y * axis.y * t + c;
	rot.mat[1][2] = axis.z * axis.y * t + axis.x * s;
	rot.mat[2][0] = axis.x * axis.z * t + axis.y * s;
	rot.mat[2][1] = axis.y * axis.z * t - axis.x * s;
	rot.mat[2][2] = axis.z * axis.z * t + c;
	return (calculate1(&tmp, &rot));
}
