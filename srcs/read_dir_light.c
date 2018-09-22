/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:09:26 by marvin            #+#    #+#             */
/*   Updated: 2018/09/20 18:09:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_dir_light_info(t_light *lit, char *line)
{
	if (ft_strequ(line, "dir["))
	{
		if (!(get_tvec3(&lit->dir, line, 4)))
			return (0);
	}
	else if (ft_strequ(line, "intensity["))
	{
		if (!(get_double(&lit->intensity, line, 10)))
			return (0);
	}
    else if (ft_strequ(line, "colour["))
	{
		if (!(get_tcol(&lit->col, line, 7)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		make_dir_light(int fd, t_vector *set)
{
	int		i;
	t_light lit;
	char	*line;

	i = 1;
	lit = light_new((t_vec3){3, -3, -10}, 0.3, (t_colour){255, 255, 255});
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (ft_strequ(line, ""))
			continue ;
		else if (ft_strequ(line, "}"))
		{
			vector_add(set, &lit);
			printf("New light: dir[%f, %f, %f], intensity[%f], colour[%f, %f, %f]\n", lit.dir.x, lit.dir.y, lit.dir.z, lit.intensity, lit.col.r, lit.col.g, lit.col.b);
			ft_strdel(&line);
			return (1);
		}
		else if (!(get_dir_light_info(&lit, line)))
			break ;
		else
			break ;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	return (0);
}
