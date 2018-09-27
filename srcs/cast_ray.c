/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:35:20 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:18:10 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		cast_ray(t_vector *s, t_ray r)
{
	int		j;
	t_shape	*cur_shp;

	j = -1;
	while (++j < s->total)
	{
		cur_shp = (t_shape *)vector_get(s, j);
		if (cur_shp->ray(cur_shp, r))
			return (1);
	}
	return (0);
}
