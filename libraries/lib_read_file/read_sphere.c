/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:23:54 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/12 18:57:13 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		read_sphere(t_shape *s, char *line)
{
	if (strcheck(line, "radius["))
	{
		if (!(get_radius(line, s)))
			return (0);
	}
	else if (strcheck(line, "colour["))
	{
		if (!(get_colour(line, s)))
			return (0);
	}
	else if (strcheck(line, "texture["))
	{
		if (!(get_texture(line, s)))
			return (0);
	}
	else if (strcheck(line, "pos[") || strcheck(line, "rot[") || strcheck(line, "scale["))
	{
		if (!(get_transform(line, s)))
			return (0);
	}
	else if (strcheck(line, "}"))
		return (2);
	else
		return (0);
	return (1);
}

int		read_sphere_info(int fd, t_shape *s, char *line)
{
	int		i;
	int		j;
	int		l;
	char	*line;

	i = 1;
	l = 0;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0)
		{
			if (l == 0 && !(strcheck(line, "{")))
				ft_exit ();
			j = read_sphere(&s, line);
			if (j == 0)
				ft_exit();
			else if (j == 2)
				return (2);
		}
		else
			break ;
		l++;
	}
	return (1);
}

int		ft_make_sphere(int fd, t_vector *set)
{
	int		i;
	int		j;
	char	*line;
	t_shape sphere;

	sphere = sphere_new((t_vec3){0, 0, 0}, 0, (t_colour){0, 0, 0});
	i = 1;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0)
		{
			j = read_sphere_info(fd, &sphere, line);
			if (j == 0)
				ft_exit();
			else if (j == 2)
				return (1);
		}
		else
			break ;
	}
	return (0);
}