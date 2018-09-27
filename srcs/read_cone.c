/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 10:35:22 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 11:00:11 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_cone_info(t_shape *cone, char *line)
{
	t_vec3	axis;
	double	angle;

	if (ft_strequ("\tradius[", line))
		return (!(get_double(&cone->radius, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_tvec3(&cone->pos, line, 5))) ? (0) : (1);
	else if (ft_strequ("\taxis[", line))
	{
		printf("Axis found\n");
		if (!(get_tvec3(&axis, line, 6)))
		{
			printf("Axis failed\n");
			return (0);
		}
		printf("Axis success 1\n");
		cone->norm = vec3_nor_cpy(axis);
		angle = acos(vec3_dot((t_vec3){0, 1, 0}, axis) / vec3_len(axis));
		cone->imat = matrix_axis_rot(vec3_crs(axis, (t_vec3){0, 1, 0}), -angle);
		cone->mat = matrix_inverse(&cone->imat);
		printf("Axis success 2\n");
	}
	else if (ft_strequ("\tcolour[", line))
		return (!(get_tcol(&cone->col, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_double(&cone->tex, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		make_cone(int fd, t_vector **set)
{
	int		i;
	t_shape *cone;
	char	*line;

	printf("Make Cone\n");
	i = 1;
	cone = cone_new((t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, 0, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		printf("Cone line [%s]\n", line);
		if (ft_strequ(line, "\0"))
			continue ;
		else if (ft_strequ("}", line))
		{
			vector_add(*set, cone);
			ft_strdel(&line);
			return (1);
		}
		else if (get_cone_info(cone, line))
		{
			printf("get_cone_info success\n");
		}
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
