/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:23:54 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/26 13:19:53 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_sphere_info(t_shape *sphere, char *line)
{
	printf("Checking get sphere info\n");
	if (ft_strequ("\tradius[", line))
	{
		if (!(get_double(&sphere->radius, line, 8)))
		{
			printf("get radius failed\n");
			return (0);
		}
		printf("get radius success\n");
	}
	else if (ft_strequ("\tpos[", line))
	{
		if (!(get_tvec3(&sphere->pos, line, 5)))
		{
			printf("get pos failed\n");
			return (0);
		}
		printf("get pos success\n");
	}
	else if (ft_strequ("\tcolour[", line))
	{
		if (!(get_tcol(&sphere->col, line, 8)))
		{
			printf("get colour failed\n");
			return (0);
		}
		printf("get colour success\n");
	}
	else if (ft_strequ("\ttexture[", line))
	{
		if (!(get_double(&sphere->tex, line, 9)))
		{
			printf("get texture failed\n");
			return (0);
		}
		// sphere->tex /= 100;
		printf("get texture success\n");
	}
	else
	{
		printf("get sphere failed\n");
		return (0);
	}
	return (1);
}

int		make_sphere(int fd, t_vector *set)
{
	int		i;
	t_shape sphere;
	char	*line;

	i = 1;
	printf("Making Sphere\n");
	sphere = sphere_new((t_vec3){0, 0, 0}, 0, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		printf("make sphere loop\n");
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		printf("make sphere line: %s\n", line);
		if (ft_strequ(line, "\0"))
			continue ;
		else if (ft_strequ("}", line))
		{
			vector_add(set, &sphere);
			printf("New Sphere: pos[%f, %f, %f], radius[%f], colour[%f, %f, %f], tex[%f]\n", sphere.pos.x, sphere.pos.y, sphere.pos.z, sphere.radius, sphere.col.r, sphere.col.g, sphere.col.b, sphere.tex);
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
	printf("make sphere failing\n");
	return (0);
}
