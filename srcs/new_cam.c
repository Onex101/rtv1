/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:14:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:40:29 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#include <stdio.h>

t_cam	*new_cam(t_vec3 org, t_vec3 target, double fov)
{
	t_cam *cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->org = org;
	cam->forward = vec3_sub_new(target, cam->org);
	vec3_nor(&(cam->forward));
	cam->right = vec3_crs(cam->forward, (t_vec3){0, 1, 0});
	vec3_nor(&(cam->right));
	cam->up = vec3_crs(cam->forward, cam->right);
	cam->h = tan(fov);
	cam->w = cam->h * RATIO;
	ft_putendl("Done with cam");
	return (cam);
}
