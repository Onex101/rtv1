/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_master.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:57:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:15:52 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_mat	matrix_master(t_vec3 scale, t_vec3 translate, t_vec3 rotate)
{
	t_mat		s;
	t_mat		t;
	t_mat		r;
	t_mat		m;
	t_mat		tmp;

	s = matrix_scale(scale);
	t = matrix_translate(translate);
	r = matrix_rotate(rotate);
	tmp = matrix_mult(r, t);
	m = matrix_mult(tmp, s);
	return (m);
}
