/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamma_correction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 14:17:46 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 16:21:09 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_col.h"

/*
** Exposure changes range of light
** Gamma changes the details in shadows -> colour correction
*/

void	gamma_correct(t_colour *c, double exp, double gamma)
{
	c->r = pow(c->r * exp, gamma);
	c->g = pow(c->g * exp, gamma);
	c->b = pow(c->b * exp, gamma);
}
