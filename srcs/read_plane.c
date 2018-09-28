/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:01:41 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 19:31:49 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_plane_info(t_shape *plane, char *line)
{
	if (ft_strequ("\tnorm[", line))
		return (!(get_tvec3(&plane->norm, line, 6))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_pos(plane, line, 5))) ? (0) : (1);
	else if (ft_strequ("\tcolour[", line))
		return (!(get_cols(plane, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_texture(plane, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		plane_line(char *line, t_vector *set, t_shape *plane)
{
	int		r;

	if (ft_strequ(line, "\0"))
		r = 2;
	else if (ft_strequ("}", line))
	{
		vector_add(set, plane);
		ft_strdel(&line);
		r = 1;
	}
	else if (get_plane_info(plane, line))
		r = 2;
	else
		r = 0;
	ft_strdel(&line);
	return (r);
}

int		make_plane(int fd, t_vector *set)
{
	int		i;
	int		r;
	t_shape *plane;
	char	*line;

	i = 1;
	plane = plane_new((t_vec3){0, 0, 0}, (t_vec3){0, 0, 0},
						(t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		r = plane_line(line, set, plane);
		if (r == 1)
			return (1);
		else if (r == 2)
			continue ;
		else
			return (0);
	}
	ft_strdel(&line);
	return (0);
}
