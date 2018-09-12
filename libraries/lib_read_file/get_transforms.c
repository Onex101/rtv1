/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_transforms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:42:55 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/12 18:57:08 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_pos(char *line, t_shape *s)
{
	double	x;
	double	y;
	double	z;
	int		i;

	i = 4;
	if (ft_isnum(line + 4))
		x = ft_atoi(line + 4);
	else
		return (0);
	s->pos = (t_vec3){x, y, z};
	return (1);
}

int		get_transforms(t_shape *s, char *line)
{
	if (strcheck(line, "pos["))
	{
		if (!(get_pos(line, s)))
			return (0);
		return (1);
	}
	else if (strcheck(line, "rot["))
	{
		if (!(get_rot(line, s)))
			return (0);
		return (1);
	}
	else if (strcheck(line, "scale["))
	{
		if (!(get_scale(line, s)))
			return (0);
		return (1);
	}
	return (0);
}
