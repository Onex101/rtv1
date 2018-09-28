/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:35:22 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 19:35:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// void	cone_axis(t_shape *cone, t_vec3 axis)
// {
// 	double	angle;

// 	cone->norm = vec3_nor_cpy(axis);
// 	angle = acos(vec3_dot((t_vec3){0, 1, 0}, axis) / vec3_len(axis));
// 	cone->imat = matrix_axis_rot(vec3_crs(axis, (t_vec3){0, 1, 0}), -angle);
// 	cone->mat = matrix_inverse(&cone->imat);
// }

int		get_cone_info(t_shape *cone, char *line)
{
	if (ft_strequ("\tradius[", line))
		return (!(get_radius(cone, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_pos(cone, line, 5))) ? (0) : (1);
	else if (ft_strequ("\taxis[", line))
		return (!(get_axis(cone, line, 6))) ? (0) : (1);
	else if (ft_strequ("\tcolour[", line))
		return (!(get_cols(cone, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_texture(cone, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		cone_line(char *line, t_vector *set, t_shape *cone)
{
	int		r;

	if (ft_strequ(line, "\0"))
		r = 2;
	else if (ft_strequ("}", line))
	{
		vector_add(set, cone);
		ft_strdel(&line);
		r = 1;
	}
	else if (get_cone_info(cone, line))
		r = 2;
	else
		r = 0;
	ft_strdel(&line);
	return (r);
}

int		make_cone(int fd, t_vector *set)
{
	int		i;
	int		r;
	t_shape *cone;
	char	*line;

	i = 1;
	cone = cone_new((t_vec3){0, 0, 0}, (t_vec3){0, 0, 0},
					0, (t_colour){0, 0, 0});
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		r = cone_line(line, set, cone);
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
