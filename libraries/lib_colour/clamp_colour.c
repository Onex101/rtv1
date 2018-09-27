/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp_colour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:44:27 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 16:26:37 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_col.h"

/*
** Ensures the r,g and b values are within the range
*/

void	clamp(t_colour *c, double max, double min)
{
	c->r = fmax(min, fmin(max, c->r));
	c->g = fmax(min, fmin(max, c->g));
	c->b = fmax(min, fmin(max, c->b));
}
