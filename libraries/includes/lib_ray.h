/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ray.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 12:08:36 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 18:52:51 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_RAY_H
# define LIB_RAY_H
# include "lib_vec.h"
# include "lib_shape.h"
# include "lib_col.h"

# define RAY_T_MIN 0.0001f
# define RAY_T_MAX 1.0e30f

typedef struct s_shape	t_shape;

typedef	struct	s_ray
{
	t_vec3		org;
	t_vec3		dir;
	double		max;
}				t_ray;

t_ray			ray(void);
void			ray_init(t_ray *ray, t_vec3 org, t_vec3 dir, double max);
t_ray			ray_new(t_vec3 org, t_vec3 dir, double max);
t_ray			ray_cpy(t_ray v);
t_vec2			calc_pnt(t_ray r, double t);

typedef struct	s_inter
{
	t_ray		ray;
	t_shape		*shape;
	double		t;
	t_vec3		normal;
	t_colour	col;
	double		tex;
}				t_inter;

t_inter			inter(void);
void			inter_init(t_inter *i, t_ray r);
t_inter			inter_new(t_ray r);
t_inter			inter_cpy(t_inter i);
int				inter_check(t_inter *i);
t_vec2			inter_pos(t_inter i, double t);

#endif
