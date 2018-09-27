/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 08:06:40 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:12:07 by shillebr         ###   ########.fr       */
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
