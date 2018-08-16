/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_lib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:50:37 by xeno              #+#    #+#             */
/*   Updated: 2018/08/16 18:07:07 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_LIB_H
# define VEC3_LIB_H
# include <math.h>
# include <string.h>

typedef	struct	s_vec3
{
	double		x;
	double		y;
	double		z;
}				t_vec3;

void	vec3_init(t_vec3 *v, double x, double y, double z);
t_vec3	*vec3_new(double x, double y, double z);
t_vec3	*vec3_cpy(t_vec3 *v);
void	vec3_del(t_vec3 *v);

void	vec3_add(t_vec3 *v1, t_vec3 *v2);
void	vec3_sub(t_vec3 *v1, t_vec3 *v2);
void	vec3_mul(t_vec3 *v, double i);
void	vec3_div(t_vec3 *v, double i);

double	vec3_len(t_vec3 *v);

void	vec3_nor(t_vec3 *v);
t_vec3 *vec3_nor_cpy(t_vec3 *v);

double	vec3_dot(t_vec3 *v1, t_vec3 *v2);
t_vec3	*vec3_crs(t_vec3 *v1, t_vec3 *v2);

#endif