/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:06:40 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/11 08:08:15 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_mat	matrix_scale(t_vec3 scale)
{
	t_mat	ret;

	matrix_identity(&ret);
	ret.mat[0][0] = scale.x;
	ret.mat[1][1] = scale.y;
	ret.mat[2][2] = scale.z;
	return (ret);
}