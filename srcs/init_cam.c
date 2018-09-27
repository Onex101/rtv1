/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:10:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:23:46 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_cam(t_cam *cam, t_vec3 org, t_vec3 target, double fov)
{
	cam->forward = vec3_sub_new(target, org);
	vec3_nor(&(cam->forward));
	cam->right = vec3_crs(cam->forward, (t_vec3){0, 1, 0});
	vec3_nor(&(cam->right));
	cam->up = vec3_crs(cam->forward, cam->right);
	cam->h = tan(fov);
	cam->w = cam->h * RATIO;
}
