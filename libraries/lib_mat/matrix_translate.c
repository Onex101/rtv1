/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:10:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/11 08:08:46 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_mat	matrix_translate(t_vec3 trans)
{
	t_mat	ret;

	matrix_identity(&ret);
	ret.mat[3][0] = trans.x;
	ret.mat[3][1] = trans.y;
	ret.mat[3][2] = trans.z;
	return (ret);
}




