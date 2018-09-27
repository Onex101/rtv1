/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:43:27 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:40:54 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_colour	get_colour(t_param *p, t_inter *in, t_ray r)
{
	t_light		*l;
	int			i;
	int			total;
	t_colour	clr;
	t_colour	total_clr;

	total = vector_total(p->lis);
	i = -1;
	total_clr = (t_colour){0, 0, 0};
	while (++i < total)
	{
		l = (t_light *)vector_get(p->lis, i);
		clr = calc_light(l, p, in, r);
		total_clr = (t_colour){total_clr.r + clr.r,
								total_clr.g + clr.g,
								total_clr.b + clr.b};
	}
	gamma_correct(&(total_clr), 1, 2.2);
	clamp(&(total_clr), 255, 0);
	return (total_clr);
}
