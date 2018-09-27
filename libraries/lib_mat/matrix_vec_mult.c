/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vec_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:59:15 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:11:01 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_vec3	matrix_vec_mult(t_vec3 source, t_mat mat)
{
	t_vec3 dest;

	dest.x = source.x * mat.mat[0][0] +
			source.y * mat.mat[0][1] +
			source.z * mat.mat[0][2] +
			mat.mat[0][3];
	dest.y = source.x * mat.mat[1][0] +
			source.y * mat.mat[1][1] +
			source.z * mat.mat[1][2] +
			mat.mat[1][3];
	dest.z = source.x * mat.mat[2][0] +
			source.y * mat.mat[2][1] +
			source.z * mat.mat[2][2] +
			mat.mat[2][3];
	return (dest);
}
