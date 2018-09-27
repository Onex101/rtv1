/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 16:37:10 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 17:01:25 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H
# include "lib_ray.h"
# include "vector.h"
# include "lib_col.h"
# include "lib_mat.h"

typedef struct s_ray	t_ray;
typedef struct s_inter	t_inter;

typedef struct s_shape	t_shape;

typedef int				(*t_intercept)(t_shape *shape, t_inter *inter);
typedef int				(*t_rayc)(t_shape *shape, t_ray ray);
typedef	t_vec3			(*t_normal)(t_shape *shape, t_vec3 hit_pnt);

struct					s_shape
{
	t_vec3				pos;
	t_vec3				norm;
	double				radius;
	double				height;
	t_intercept			inter;
	t_rayc				ray;
	t_normal			hit_nor;
	t_colour			col;
	double				tex;
	t_mat				mat;
	t_mat				imat;
};

#endif
