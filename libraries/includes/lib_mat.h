/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_mat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 18:12:42 by xeno              #+#    #+#             */
/*   Updated: 2018/09/25 18:42:29 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MAT_H
# define LIB_MAT_H
# include "lib_vec.h"
# include "lib_ft.h"

typedef struct	s_mat
{
	double		mat[4][4];
}				t_mat;

void			matrix_cpy(t_mat *source, t_mat *dest);
t_mat			matrix_mult(t_mat mat1, t_mat mat2);
t_vec3			matrix_vec_mult(t_vec3 source, t_mat mat);
void			matrix_identity(t_mat *mat);
t_mat			matrix_translate(t_vec3 trans);
t_mat			matrix_scale(t_vec3 scale);
t_mat			matrix_rotate(t_vec3 rot);
t_mat			matrix_master(t_vec3 s, t_vec3 t, t_vec3 r);
t_mat			matrix_inverse(t_mat *mat);
void			matrix_print(t_mat *mat);

t_mat			matrix_transpose(t_mat *m);
void			matrix_divide_row(t_mat *m, int i, double div);
void			matrix_sub_row(t_mat *m, int i, int j, double sub);
void			matrix_swap_row(t_mat *m, int i, int j);
void			matrix_sub_row(t_mat *m, int i, int j, double sub);
t_mat			matrix_inverse(t_mat *m);
int				matrix_get_row(t_mat *m, int i);
t_mat			matrix_axis_rot(t_vec3 axis, double angle);

#endif
