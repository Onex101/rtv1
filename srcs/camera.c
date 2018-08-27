/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:14:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/27 12:45:46 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	cam_init(t_cam *cam, t_vec3 org, t_vec3 target, t_vec3 up, double fov, double aspect_ratio)
{
	cam->forward = vec3_sub_new(target, org);
	vec3_norm(cam->forward);
	cam->right = vec3_crs(cam->forward, up);
	vec3_norm(cam->right);
	cam->up = vec3_crs(cam->forward, cam->right);
	cam->h = tan(fov);
	cam->w = cam->h * aspect_ratio; 
}

t_ray	make_ray(t_cam cam, t_vec3 pnt)
{
	t_vec3 dir;
	t_vec3 tmp1;
	t_vec3 tmp2;
	t_ray new;

	tmp1 = vec3_mul_new(cam.right, cam.w * pnt.x);
	tmp2 = vec3_mul_new(cam.up, cam.h * pnt.y);
	vec3_add(&tmp1, tmp2); 
	dir = vec3_add_new(cam.forward, tmp1);
	vec3_nor(&dir);
	return(ray_new(cam.org, dir, RAY_T_MAX));
}