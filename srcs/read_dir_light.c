/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dir_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:45:47 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/28 07:55:37 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_dir_light_info(t_light *lit, char *line)
{
	if (ft_strequ("\tdir[", line))
	{
		if (!(get_dir(lit, line, 5)))
			return (0);
	}
	else if (ft_strequ("\tintensity[", line))
	{
		if (!(get_intensity(lit, line, 11)))
			return (0);
	}
	else if (ft_strequ("\tcolour[", line))
	{
		if (!(get_l_cols(lit, line, 8)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		dir_light_line(char *line, t_vector *set, t_light *lit)
{
	int		r;

	if (ft_strequ(line, "\0"))
		r = 2;
	else if (ft_strequ("}", line))
	{
		vector_add(set, lit);
		ft_strdel(&line);
		r = 1;
	}
	else if (get_dir_light_info(lit, line))
		r = 2;
	else
		r = 0;
	ft_strdel(&line);
	return (r);
}

int		make_dir_light(int fd, t_vector *set)
{
	int		i;
	int		r;
	t_light *lit;
	char	*line;

	i = 1;
	lit = light_new((t_vec3){3, -3, -10}, 0.3,
			(t_colour){255, 255, 255});
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		r = dir_light_line(line, set, lit);
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
