/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:23:54 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/26 14:30:55 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_sphere_info(t_shape *sphere, char *line)
{
	if (ft_strequ("\tradius[", line))
		return (!(get_double(&sphere->radius, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_tvec3(&sphere->pos, line, 5))) ? (0) : (1);
	else if (ft_strequ("\tcolour[", line))
		return (!(get_tcol(&sphere->col, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_double(&sphere->tex, line, 9))) ? (0) : (1);
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
		if (ft_strequ(line, "\0"))
			continue ;
		else if (ft_strequ("}", line))
		{
			vector_add(set, &sphere);
			printf("Sphere: pos[%f, %f, %f], radius[%f], texture[%f], col[%f, %f, %f]\n", sphere.pos.x, sphere.pos.y, sphere.pos.z, sphere.radius, sphere.tex, sphere.col.r, sphere.col.g, sphere.col.b);
			ft_strdel(&line);
			return (1);
		}
		else if (get_sphere_info(&sphere, line))
		{
			printf("get_sphere_info success\n");
		}
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
