/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:08:37 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:55:43 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"

int	set_inter(t_vector *s, t_inter *i)
{
	int		check;
	int		j;
	int		total;
	t_shape	*cur_shp;

	total = vector_total(s);
	check = 0;
	j = -1;
	while (++j < total)
	{
		cur_shp = (t_shape *)vector_get(s, j);
		if (cur_shp->inter(cur_shp, i))
		{
			check = 1;
			i->col = cur_shp->col;
			i->tex = cur_shp->tex;
		}
	}
	return (check);
}

int	set_ray_inter(t_vector *s, t_ray ray)
{
	int		j;
	int		total;
	t_shape	*cur_shp;

	total = vector_total(s);
	j = -1;
	while (++j < total)
	{
		cur_shp = (t_shape *)vector_get(s, j);
		if (cur_shp->ray(cur_shp, ray))
			return (1);
	}
	return (0);
}
