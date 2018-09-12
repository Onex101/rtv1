/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:21 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/12 18:57:11 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_objects(int fd, t_vector *set, char *line)
{
	int		i;

	if (ft_strequ(line, "Sphere"))
		i = ft_make_sphere(fd, set);//t_vector stores all the shapes, verctor add
	else if (ft_strequ(line, "Plane"))
		i = ft_make_plane(fd, set);
	else if (ft_strequ(line, "Cylinder"))
		i = ft_make_cylinder(fd, set);
	else if (ft_strequ(line, "Cone"))
		i = ft_make_cone(fd, set);
	else if (ft_strequ(line, ""))
		return (1);
	else
		i = 0;	
	return (i); // not sure about this, might not be valid
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
		if (ft_strequ(line, "Sphere") || ft_strequ(line, "Plane") || ft_strequ(line, "")
			|| ft_strequ(line, "Cylinder") || ft_strequ(line, "Cone"))
			check_objects(fd, set, line);
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