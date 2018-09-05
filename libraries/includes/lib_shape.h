/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_shape.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:58:46 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/05 08:36:20 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SHAPE_H
# define LIB_SHAPE_H

#include "lib_ray.h"
#include "vector.h"

typedef struct s_ray	t_ray;
typedef struct s_inter	t_inter;

typedef struct s_shape	t_shape;

typedef int	(*inter_c)(t_shape *shape, t_inter inter);
typedef int	(*ray_check)(t_shape *shape, t_ray ray);

struct	s_shape
{
	t_vec3		pos;
	t_vec3		norm;
	double		radius;
	inter_c		inter;
	ray_check	ray;
};


t_shape		plane_new(t_vec3 pos, t_vec3 norm);
t_shape		sphere_new(t_vec3 pos, double radius);

int			set_inter(t_vector *s, t_inter i);
int 		set_ray_inter(t_vector *s, t_ray ray);
int			plane_inter(t_shape *plane, t_inter i);
int			plane_ray(t_shape *plane, t_ray ray);
int			sphere_inter(t_shape *sphere, t_inter i);
int			sphere_ray(t_shape *sphere, t_ray r);

#endif