/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:13:22 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 19:31:50 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		cam_line(char *line, t_cam *c)
{
	int		r;

	if (line[0] == '\0')
		r = 2;
	else if (ft_strequ("}\0", line))
		r = 1;
	else if ((is_cam_info(line)))
	{
		if (!(get_cam_info(c, line)))
			r = 0;
		else
			r = 2;
	}
	else
		r = 0;
	ft_strdel(&line);
	return (r);
}

int		get_cam(int fd, t_cam *c)
{
	int		i;
	int		r;
	char	*line;

	i = 1;
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		r = cam_line(line, c);
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

int		is_cam(char *line)
{
	if (ft_strequ(line, "Camera{"))
		return (1);
	return (0);
}

int		read_camera(int fd, t_cam *c)
{
	int		i;
	char	*line;

	i = 1;
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (is_cam(line))
		{
			if (!(get_cam(fd, c)))
				return (0);
		}
		else if (ft_strequ(line, "\0"))
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
