/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 11:04:06 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 11:16:32 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_cyl_info(t_shape *cyl, char *line)
{
	t_vec3	axis;
	double	angle;

	if (ft_strequ("\tradius[", line))
		return (!(get_double(&cyl->radius, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tpos[", line))
		return (!(get_tvec3(&cyl->pos, line, 5))) ? (0) : (1);
	else if (ft_strequ("\taxis[", line))
	{
		printf("Axis found\n");
		if (!(get_tvec3(&axis, line, 6)))
		{
			printf("Axis failed\n");
			return (0);
		}
		printf("Axis success 1\n");
		cyl->norm = vec3_nor_cpy(axis);
		angle = acos(vec3_dot((t_vec3){0, 1, 0}, axis) / vec3_len(axis));
		cyl->imat = matrix_axis_rot(vec3_crs(axis, (t_vec3){0, 1, 0}), -angle);
		cyl->mat = matrix_inverse(&cyl->imat);
		printf("Axis success 2\n");
	}
	else if (ft_strequ("\tcolour[", line))
		return (!(get_tcol(&cyl->col, line, 8))) ? (0) : (1);
	else if (ft_strequ("\ttexture[", line))
		return (!(get_double(&cyl->tex, line, 9))) ? (0) : (1);
	else
		return (0);
	return (1);
}

int		make_cyl(int fd, t_vector **set)
{
	int		i;
	t_shape *cyl;
	char	*line;

	printf("Make cyl\n");
	i = 1;
	cyl = cyl_new((t_vec3){0, 0, 0}, (t_vec3){0, 0, 0}, 0, (t_colour){0, 0, 0}, 0);
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		printf("cyl line [%s]\n", line);
		if (ft_strequ(line, "\0"))
			continue ;
		else if (ft_strequ("}", line))
		{
			vector_add(*set, cyl);
			ft_strdel(&line);
			return (1);
		}
		else if (get_cyl_info(cyl, line))
		{
			printf("get_cyl_info success\n");
		}
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
