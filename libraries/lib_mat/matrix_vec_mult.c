/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_vec_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:59:15 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/11 16:59:29 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_vec3	matrix_vec_mult(t_vec3 source, t_mat mat)
{
	t_vec3 dest;

	dest.x =	source.x * mat.mat[0][0] +
				source.y * mat.mat[1][0] +
				source.z * mat.mat[2][0] +
							mat.mat[3][0];
	dest.y =	source.x * mat.mat[0][1] +
				source.y * mat.mat[1][1] +
				source.z * mat.mat[2][1] +
							mat.mat[3][1];
	dest.z =	source.x * mat.mat[0][2] +
				source.y * mat.mat[1][2] +
				source.z * mat.mat[2][2] +
							mat.mat[3][2];
	return (dest);
}