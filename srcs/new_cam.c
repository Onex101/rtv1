/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 10:14:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/03 16:01:41 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam	*new_cam(t_vec3 org, t_vec3 target, t_vec3 up, double fov, double aspect_ratio)
{
	t_cam *cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	cam->forward = vec3_sub_new(target, org);
	vec3_nor(&(cam->forward));
	cam->right = vec3_crs(cam->forward, up);
	vec3_nor(&(cam->right));
	cam->up = vec3_crs(cam->forward, cam->right);
	cam->h = tan(fov);
	cam->w = cam->h * aspect_ratio;
	ft_putendl("Done with cam");
	return (cam);
}