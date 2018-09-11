/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:46:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/11 13:52:04 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static	void	cr_mat(t_mat *m, t_vec3 mx, t_vec3 my, t_vec3 mz, t_cam *c)
{
	m->mat[0][0] = mx.x;
	m->mat[0][1] = my.x;
	m->mat[0][2] = mz.x;
	m->mat[0][3] = 0;
	m->mat[1][0] = mx.y;
	m->mat[1][1] = my.y;
	m->mat[1][2] = mz.y;
	m->mat[1][3] = 0;
	m->mat[2][0] = mx.z;
	m->mat[2][1] = my.z;
	m->mat[2][2] = mz.z;
	m->mat[2][3] = 0;
	m->mat[3][0] = vec3_dot(mx, c->org);
	m->mat[3][1] = vec3_dot(my, c->org);
	m->mat[3][2] = -vec3_dot(mz, c->org);
	m->mat[3][3] = 1;
}

t_mat			look_at(t_cam *c)
{
	t_vec3 mz;
	t_vec3 my;
	t_vec3 mx;
	t_mat cam;

	matrix_identity(&cam);
	mz = vec3_nor_cpy((t_vec3){c->org.x - c->tar.x, c->org.y - c->tar.y, c->org.z - c->tar.z});
	mx = vec3_nor_cpy(vec3_crs(mz, c->up));
	my = vec3_crs(mz, mx);
	cr_mat(&cam, mx, my, mz, c);
	return (cam);
}