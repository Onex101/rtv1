/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_col.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:18:13 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 17:03:58 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_COL_H
# define LIB_COL_H
# include <math.h>

typedef struct	s_colour
{
	double		r;
	double		g;
	double		b;
}				t_colour;

/*
** colour_operations
*/
void			col_copy(t_colour *dest, t_colour src);
void			col_add(t_colour *dest, t_colour c);
void			col_mult(t_colour *dest, t_colour c);
void			col_f_mult(t_colour *dest, double f);
/*
** colour_operations_new
*/
t_colour		col_copy_new(t_colour c);
t_colour		col_add_new(t_colour a, t_colour b);
t_colour		col_mult_new(t_colour a, t_colour b);
t_colour		col_f_mult_new(t_colour a, double f);
/*
** clamp_colour
*/
void			clamp(t_colour *c, double max, double min);
void			gamma_correct(t_colour *c, double exp, double gamma);
unsigned long	rgb_to_hex(int r, int g, int b);

#endif
