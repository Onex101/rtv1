/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 13:59:18 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 19:32:14 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		check_lights(int fd, t_vector *set, char *line)
{
	int		i;

	if (ft_strequ(line, "Dir Light{"))
		i = make_dir_light(fd, set);
	else if (ft_strequ(line, ""))
		i = 1;
	else
		i = 0;
	return (i);
}

int		is_light(char *line)
{
	if (ft_strequ(line, "Dir Light{"))
		return (1);
	return (0);
}

int		read_lights(int fd, t_vector *set)
{
	int		i;
	char	*line;

	i = 1;
	ft_putendl("Reading Lights");
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			break ;
		if (is_light(line))
			check_lights(fd, set, line);
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
	return (1);
}
