/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_lib.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:10:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/16 18:12:16 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat_lib.h"
#include "vec3_lib.h"

t_mat	*matrix_translate(t_vec3 *trans)
{
	t_mat	*ret;

	ret = (t_mat *)malloc(sizeof(t_mat));
	matrix_identity(ret);
	ret->mat[3][0] = trans->x;
	ret->mat[3][1] = trans->y;
	ret->mat[3][2] = trans->z;
	return (ret);
}

t_mat	*matrix_scale(t_vec3 *scale)
{
	t_mat	*ret;

	ret = (t_mat *)malloc(sizeof(t_mat));
	matrix_identity(ret);
	ret->mat[0][0] = scale->x;
	ret->mat[1][1] = scale->y;
	ret->mat[2][2] = scale->z;
	return (ret);
}

void	set_rot_mat(t_mat *xmat, t_mat *ymat, t_mat *zmat, t_vec3 *rot)
{
	xmat->mat[1][1] = cos(rot->x);
	xmat->mat[1][2] = sin(rot->x);
	xmat->mat[2][1] = -sin(rot->x);
	xmat->mat[2][2] = cos(rot->x);
	ymat->mat[0][0] = cos(rot->y);
	ymat->mat[0][2] = -sin(rot->y);
	ymat->mat[2][0] = sin(rot->y);
	ymat->mat[2][2] = cos(rot->y);
	zmat->mat[0][0] = cos(rot->z);
	zmat->mat[0][1] = sin(rot->z);
	zmat->mat[1][0] = -sin(rot->z);
	zmat->mat[1][1] = cos(rot->z);
}

t_mat	*matrix_rotate(t_vec3 *rot)
{
	t_mat *xmat;
	t_mat *ymat;
	t_mat *zmat;
	t_mat *ret;
	t_mat *tmp;

	matrix_identity(xmat = (t_mat *)malloc(sizeof(t_mat)));
	matrix_identity(ymat = (t_mat *)malloc(sizeof(t_mat)));
	matrix_identity(zmat = (t_mat *)malloc(sizeof(t_mat)));
	set_rot_mat(xmat, ymat, zmat, rot);
	tmp = matrix_mult(xmat, ymat);
	ret = matrix_mult(tmp, zmat);
	free(xmat);
	free(ymat);
	free(tmp);
	free(zmat);
	return (ret);
}
