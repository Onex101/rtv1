/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:14:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/04 13:36:06 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_cam	*new_cam(t_vec3 org, t_vec3 target, t_vec3 upguide, double fov, double aspect_ratio)
{
	t_cam *cam;

	printf("Cam org = x[%f] y[%f] z[%f]\n", org.x, org.y, org.z);
	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->org = org;
	cam->forward = vec3_sub_new(target, cam->org);
	vec3_nor(&(cam->forward));
	printf("Cam forward = x[%f] y[%f] z[%f]\n", cam->forward.x, cam->forward.y, cam->forward.z);
	cam->right = vec3_crs(cam->forward, upguide);
	vec3_nor(&(cam->right));
	printf("Cam right = x[%f] y[%f] z[%f]\n", cam->right.x, cam->right.y, cam->right.z);
	cam->up = vec3_crs(cam->forward, cam->right);
	printf("Cam up = x[%f] y[%f] z[%f]\n", cam->up.x, cam->up.y, cam->up.z);
	cam->h = tan(fov);
	cam->w = cam->h * aspect_ratio;
	ft_putendl("Done with cam");
	return (cam);

}

/*
** forward = (target - orign) normalize
** right = crs(forward, upguide) normalize
** up = crs(forward, cam->right);
*/
