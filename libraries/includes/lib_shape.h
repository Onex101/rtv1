/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_shape.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 10:58:46 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:40:02 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_SHAPE_H
# define LIB_SHAPE_H

# include "lib_ray.h"
# include "vector.h"
# include "lib_col.h"
# include "lib_mat.h"
# include "shape.h"

t_shape		*plane_new(t_vec3 pos, t_vec3 norm, t_colour col, double tex);
t_shape		*sphere_new(t_vec3 pos, double radius, t_colour col, double tex);
t_shape		*cyl_new(t_vec3 pos, t_vec3 axis, double radius, t_colour col);
t_shape		*cone_new(t_vec3 pos, t_vec3 axis, double rad, t_colour col);
int			set_inter(t_vector *s, t_inter *i);
int			set_ray_inter(t_vector *s, t_ray ray);
int			plane_inter(t_shape *plane, t_inter *i);
int			plane_ray(t_shape *plane, t_ray ray);
int			sphere_inter(t_shape *sphere, t_inter *i);
int			sphere_ray(t_shape *sphere, t_ray r);
int			cyl_inter(t_shape *s, t_inter *i);
int			cyl_ray(t_shape *s, t_ray l_ray);
int			cone_inter(t_shape *c, t_inter *i);
int			cone_ray(t_shape *c, t_ray l_ray);
t_vec3		sphere_hit_norm(t_shape *s, t_vec3 hit);

#endif
