/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:44:31 by marvin            #+#    #+#             */
/*   Updated: 2018/09/20 17:44:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_plane_info(t_shape *plane, char *line)
{
	if (ft_strequ(line, "pos["))
	{
		if (!(get_tvec3(&plane->pos, line, 4)))
			return (0);
	}
	else if (ft_strequ(line, "norm["))
	{
		if (!(get_tvec3(&plane->norm, line, 5)))
			return (0);
	}
	else if (ft_strequ(line, "colour["))
	{
		if (!(get_tcol(&plane->col, line, 7)))
			return (0);
	}
	else if (ft_strequ(line, "texture["))
	{
		if (!(get_double(&plane->tex, line, 8)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		make_plane(int fd, t_vector *set)
{
	int		i;
	t_shape plane;
	char	*line;

	i = 1;
	plane = plane_new((t_vec3){0, 0, 0}, (t_vec3){0, 1, 0}, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (ft_strequ(line, ""))
			continue ;
		else if (ft_strequ(line, "}"))
		{
			vector_add(set, &plane);
			printf("New Plane: pos[%f, %f, %f], norm[%f, %f, %f], colour[%f, %f, %f], tex[%f]\n", plane.pos.x, plane.pos.y, plane.pos.z, plane.norm.x, plane.norm.y, plane.norm.z, plane.col.r, plane.col.g, plane.col.b, plane.tex);
			ft_strdel(&line);
			return (1);
		}
		else if (!(get_plane_info(&plane, line)))
			break ;
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
