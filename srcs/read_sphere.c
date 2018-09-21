/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:23:54 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/21 13:25:35 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_sphere_info(t_shape *sphere, char *line)
{
	if (ft_strequ(line, "radius["))
	{
		if (!(get_double(&sphere->radius, line, 7)))
			return (0);
	}
	else if (ft_strequ(line, "pos["))
	{
		if (!(get_tvec3(&sphere->pos, line, 4)))
			return (0);
	}
	else if (ft_strequ(line, "colour["))
	{
		if (!(get_tcol(&sphere->col, line, 7)))
			return (0);
	}
	else if (ft_strequ(line, "texture["))
	{
		if (!(get_double(&sphere->tex, line, 8)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		make_sphere(int fd, t_vector *set)
{
	int		i;
	t_shape sphere;
	char	*line;

	i = 1;
	sphere = sphere_new((t_vec3){0, 0, 0}, 0, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (ft_strequ(line, ""))
			continue ;
		else if (ft_strequ(line, "}"))
		{
			vector_add(set, &sphere);
			printf("New Sphere: pos[%f, %f, %f], radius[%f], colour[%f, %f, %f], tex[%f]\n", sphere.pos.x, sphere.pos.y, sphere.pos.z, sphere.radius, sphere.col.r, sphere.col.g, sphere.col.b, sphere.tex);
			ft_strdel(&line);
			return (1);
		}
		else if (!(get_sphere_info(&sphere, line)))
			break ;
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
