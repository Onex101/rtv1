/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_operations_new.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:19:14 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/05 17:42:53 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_col.h"

t_colour	col_copy_new(t_colour c)
{
	t_colour	new;

	new.r = c.r;
	new.g = c.g;
	new.b = c.b;
	return (new);
}

t_colour	col_add_new(t_colour a, t_colour b)
{
	t_colour	new;

	new.r = a.r + b.r;
	new.g = a.g + b.g;
	new.b = a.b + b.b;
	return (new);
}

t_colour	col_mult_new(t_colour a, t_colour b)
{
	t_colour	new;

	new.r = a.r * b.r;
	new.g = a.g * b.g;
	new.b = a.b * b.b;
	return (new);
}

t_colour	col_f_mult_new(t_colour a, double f)
{
	t_colour	new;

	new.r = a.r * f;
	new.g = a.g * f;
	new.b = a.b * f;
	return (new);
}
