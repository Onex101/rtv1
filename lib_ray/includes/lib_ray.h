/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ray.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:08:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/20 15:39:04 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RAY_H
# define LIB_RAY_H
# include <math.h>
# include <string.h>
# include "lib_vec.h"

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f

typedef	struct	s_ray
{
	t_vec2		org;
	t_vec3		dir;
	double		max;
}				t_ray;

void	ray_init(t_ray *ray,  t_vec2 org, t_vec3 dir, double max);
t_ray	ray_new(t_vec2 org, t_vec3 dir, double max);
t_ray	ray_cpy(t_ray v);
t_vec2	calc_pnt(t_ray r, double t);

typedef struct	s_inter
{
	t_ray		ray;
	t_shape		shape;
	double		t;
}				t_inter;

void	inter_init(t_inter *i, t_ray r, t_shape s, double t);
t_inter	inter_new(t_ray r, t_shape s, double t);
t_inter inter_cpy(t_inter i);
int		inter_check(t_inter *i);
t_vec2	inter_pos(t_inter i, double t);

typedef struct	s_shape
{

}				t_shape;
// void	vec2_add(t_vec2 *v1, t_vec2 *v2);
// void	vec2_sub(t_vec2 *v1, t_vec2 *v2);
// void	vec2_mul(t_vec2 *v, double i);
// void	vec2_div(t_vec2 *v, double i);

#endif