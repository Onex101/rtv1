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
	if (ft_strequ("\tnorm[", line))
		return (!(get_tvec3(&plane->norm, line, 6))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_tvec3(&plane->pos, line, 5))) ? (0) : (1);
	else if (ft_strequ("\tcolour[", line))
		return (!(get_tcol(&plane->col, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_double(&plane->tex, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		make_plane(int fd, t_vector **set)
{
	int		i;
	t_shape *plane;
	char	*line;

	i = 1;
	plane = plane_new((t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (ft_strequ(line, "\0"))
			continue ;
		else if (ft_strequ("}", line))
		{
			vector_add(*set, plane);
			ft_strdel(&line);
			return (1);
		}
		else if (get_plane_info(plane, line))
		{
			printf("get_plane_info success\n");
		}
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
