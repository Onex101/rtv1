/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:08:57 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:11:27 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray	make_ray(t_cam *cam, t_vec3 pnt)
{
	t_vec3 dir;
	t_vec3 tmp1;
	t_vec3 tmp2;

	tmp1 = vec3_mul_new(cam->right, cam->w * pnt.x);
	tmp2 = vec3_mul_new(cam->up, cam->h * pnt.y);
	vec3_add(&tmp1, tmp2);
	dir = vec3_add_new(cam->forward, tmp1);
	vec3_nor(&dir);
	return (ray_new(cam->org, dir, RAY_T_MAX));
}
