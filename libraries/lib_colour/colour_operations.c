/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:07:11 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 16:20:59 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_col.h"

void	col_copy(t_colour *dest, t_colour src)
{
	dest->r = src.r;
	dest->g = src.g;
	dest->b = src.b;
}

void	col_add(t_colour *dest, t_colour c)
{
	dest->r += c.r;
	dest->g += c.g;
	dest->b += c.b;
}

void	col_mult(t_colour *dest, t_colour c)
{
	dest->r *= c.r;
	dest->g *= c.g;
	dest->b *= c.b;
}

void	col_f_mult(t_colour *dest, double f)
{
	dest->r *= f;
	dest->g *= f;
	dest->b *= f;
}
