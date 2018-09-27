/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_project.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:11:05 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:32:27 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

t_vec3	vec3_project(t_vec3 u, t_vec3 v)
{
	t_vec3	proj;
	double	dot;

	dot = vec3_dot(u, v) / vec3_dot(v, v);
	proj = vec3_mul_new(v, dot);
	return (proj);
}
