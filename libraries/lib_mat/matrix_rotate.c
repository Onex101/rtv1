/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:05:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:12:11 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

static	void	set_rot_mat(t_mat *xmat, t_mat *ymat, t_mat *zmat, t_vec3 rot)
{
	xmat->mat[1][1] = cos(rot.x);
	xmat->mat[1][2] = sin(rot.x);
	xmat->mat[2][1] = -sin(rot.x);
	xmat->mat[2][2] = cos(rot.x);
	ymat->mat[0][0] = cos(rot.y);
	ymat->mat[0][2] = -sin(rot.y);
	ymat->mat[2][0] = sin(rot.y);
	ymat->mat[2][2] = cos(rot.y);
	zmat->mat[0][0] = cos(rot.z);
	zmat->mat[0][1] = sin(rot.z);
	zmat->mat[1][0] = -sin(rot.z);
	zmat->mat[1][1] = cos(rot.z);
}

t_mat			matrix_rotate(t_vec3 rot)
{
	t_mat xmat;
	t_mat ymat;
	t_mat zmat;
	t_mat ret;
	t_mat tmp;

	set_rot_mat(&xmat, &ymat, &zmat, rot);
	tmp = matrix_mult(xmat, ymat);
	ret = matrix_mult(tmp, zmat);
	return (ret);
}
