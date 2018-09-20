/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:21 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/20 09:27:40 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_sphere_info(t_shape *sphere, char *line)
{
	if (ft_strequ(line, "radius["))
		if (!(get_double(sphere->radius, line, 7)))
			return (0);
	else if (ft_strequ(line, "pos["))
		if (!(get_tvec3(sphere->pos, line, 4)))
			return (0);
	else if (ft_strequ(line, "colour["))
		if (!(get_tvec3(sphere->col, line, 7)))
			return (0);
	else if (ft_strequ(line, "texture["))
		if (!(get_tvec3(sphere->tex, line, 8)))
			return (0);
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

int		check_objects(int fd, t_vector *set, char *line)
{
	int		i;

	if (ft_strequ(line, "Sphere"))
		i = make_sphere(fd, set);//t_vector stores all the shapes, verctor add
	else if (ft_strequ(line, "Plane"))
		i = make_plane(fd, set);
	else if (ft_strequ(line, "Cylinder"))
		i = make_cylinder(fd, set);
	else if (ft_strequ(line, "Cone"))
		i = make_cone(fd, set);
	else if (ft_strequ(line, ""))
		return (1);
	else
		i = 0;	
	return (i); // not sure about this, might not be valid
}

int		if_obj(char *line)
{
	if (ft_strequ(line, "Sphere") || ft_strequ(line, "Plane"))
		return (1);
	else if (ft_strequ(line, "Cylinder") || ft_strequ(line, "Cone"))
		return (1);
	return (0);
}

int		read_objects(int fd, t_vector *set)
{
	int		i;
	char	*line;

	i = 1;
	ft_putendl("Reading Objects");
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			break ;
		if (is_obj(line))
			check_objects(fd, set, line);
		else if (ft_strequ(line, ""))
			continue ;
		else if (ft_strequ(line, "#"))
			return (1);
		else
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1); // not sure about this, might not be valid
}