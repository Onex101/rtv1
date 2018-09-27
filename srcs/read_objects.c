/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:17:21 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 11:17:33 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_objects(int fd, t_vector **set, char *line)
{
	int		i;

	if (ft_strequ(line, "Sphere{"))
		i = make_sphere(fd, set);//t_vector stores all the shapes, verctor add
	else if (ft_strequ(line, "Plane{"))
		i = make_plane(fd, set);
	else if (ft_strequ(line, "Cylinder{"))
		i = make_cyl(fd, set);
	else if (ft_strequ(line, "Cone{"))
		i = make_cone(fd, set);
	else if (ft_strequ(line, "\0"))
		i = 1;
	else
		i = 0;	
	return (i); // not sure about this, might not be valid
}

int		is_obj(char *line)
{
	if (ft_strequ(line, "Sphere{") || ft_strequ(line, "Plane{"))
		return (1);
	else if (ft_strequ(line, "Cylinder{") || ft_strequ(line, "Cone{"))
		return (1);
	return (0);
}

int		read_objects(int fd, t_vector **set)
{
	int		i;
	char	*line;

	i = 1;
	ft_putendl("Reading Objects");
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			break ;
		printf("Object line [%s]\n", line);
		if (is_obj(line))
			check_objects(fd, set, line);
		else if (ft_strequ(line, "\0"))
			continue ;
		else if (ft_strequ(line, "#"))
		{
			printf("Read objects successful\n");
			return (1);
		}
		else
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}