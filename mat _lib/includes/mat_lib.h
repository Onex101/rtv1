/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:12:42 by xeno              #+#    #+#             */
/*   Updated: 2018/08/16 18:15:21 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_LIB_H
# define MAT_LIB_H

typedef struct	s_mat
{
	double		mat[4][4];
}				t_mat;

void			matrix_cpy(t_mat *source, t_mat *dest);
t_mat			*matrix_mult(t_mat *mat1, t_mat *mat2);
t_vec3			*matrix_vec_mult(t_vec3 *source, t_mat *mat);
void			matrix_identity(t_mat *mat);
t_mat			*matrix_translate(t_vec3 *trans);
t_mat			*matrix_scale(t_vec3 *scale);
t_mat			*matrix_rotate(t_vec3 *rot);
t_mat			*matrix_master(t_vec3 *s, t_vec3 *t, t_vec3 *r);

#endif