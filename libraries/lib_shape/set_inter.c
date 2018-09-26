/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 13:08:37 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:22:26 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_shape.h"
#include <stdio.h>

int	set_inter(t_vector *s, t_inter *i)
{
	int		check;
	int		j;
	int		total;
	t_shape	*cur_shp;

	// printf("set inter 1\n");	
	total = vector_total(s);
	// printf("set inter 2\n");	
	check = 0;
	// printf("set inter 3\n");
	j = -1;
	// printf("set inter 4\n");
	while (++j < total)
	{
		// printf("set inter 5\n");
		cur_shp = (t_shape *)vector_get(s, j);
		// printf("set inter 6\n");
		if (cur_shp->inter(cur_shp, i))
		{
			// printf("set inter 7\n");
			check = 1;
			// printf("set inter 8\n");
			i->col = cur_shp->col;
			// printf("set inter 9\n");
			i->tex = cur_shp->tex;
			// printf("set inter 10\n");
		}
	}
	// printf("set inter 11\n");
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
