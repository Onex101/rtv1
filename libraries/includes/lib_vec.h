/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:50:37 by xeno              #+#    #+#             */
/*   Updated: 2018/09/25 18:02:24 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_VEC_H
# define LIB_VEC_H
# include <math.h>
# include <stdlib.h>
# include <string.h>

typedef	struct	s_vec2
{
	double		x;
	double		y;
}				t_vec2;

void			vec2_init(t_vec2 *v, double x, double y);
t_vec2			vec2_new(double x, double y);
t_vec2			vec2_cpy(t_vec2 v);

void			vec2_add(t_vec2 *v1, t_vec2 v2);
void			vec2_sub(t_vec2 *v1, t_vec2 v2);
void			vec2_mul(t_vec2 *v, double i);
void			vec2_div(t_vec2 *v, double i);

t_vec2			vec2_add_new(t_vec2 v1, t_vec2 v2);
t_vec2			vec2_sub_new(t_vec2 v1, t_vec2 v2);
t_vec2			vec2_mul_new(t_vec2 v, double i);
t_vec2			vec2_div_new(t_vec2 v, double i);

typedef	struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

void			vec3_init(t_vec3 *v, double x, double y, double z);
t_vec3			vec3_new(double x, double y, double z);
t_vec3			vec3_cpy(t_vec3 v);
t_vec3			vec3(void);

void			vec3_add(t_vec3 *v1, t_vec3 v2);
void			vec3_sub(t_vec3 *v1, t_vec3 v2);
void			vec3_mul(t_vec3 *v, double i);
void			vec3_div(t_vec3 *v, double i);

t_vec3			vec3_add_new(const t_vec3 v1, const t_vec3 v2);
t_vec3			vec3_sub_new(const t_vec3 v1, const t_vec3 v2);
t_vec3			vec3_mul_new(const t_vec3 v, double i);
t_vec3			vec3_div_new(const t_vec3 v, double i);

double			vec3_len_sqr(t_vec3 v);
double			vec3_len(t_vec3 v);

double			vec3_nor(t_vec3 *v);
t_vec3			vec3_nor_cpy(t_vec3 v);

double			vec3_dot(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_crs(t_vec3 v1, t_vec3 v2);
t_vec3			vec3_project(t_vec3 u, t_vec3 v);

void			vec3_prnt(t_vec3 v);

#endif
