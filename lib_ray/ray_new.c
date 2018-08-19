/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 11:20:23 by xeno              #+#    #+#             */
/*   Updated: 2018/08/19 13:40:49 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ray.h"

t_ray ray_new(t_vec2 org, t_vec3 dis, double max)
{
	t_ray r;

	ray_init(&r, org, dis, max);
	return (r);
}