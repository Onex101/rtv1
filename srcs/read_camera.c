/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:15:22 by marvin            #+#    #+#             */
/*   Updated: 2018/09/20 18:15:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_cam_info(t_cam *c, char *line)
{
	if (ft_strequ("\torg[\0", line))
	{
		if (!(get_tvec3(&c->org, line, 5)))
			return (0);
	}
	else if (ft_strequ("\ttarget[", line))
	{
		if (!(get_tvec3(&c->tar, line, 8)))
			return (0);
	}
	else if (ft_strequ("\tupguide[", line))
	{
		if (!(get_tvec3(&c->up, line, 9)))
			return (0);
	}
	else if (ft_strequ("\tfov[", line))
	{
		if (!(get_double(&c->h, line, 5)))
			return (0);
		else
			c->h = tan(c->h);
	}
	else if (ft_strequ("\taspect_ratio[", line))
	{
		if (!(get_double(&c->w, line, 14)))
			return (0);
		else
			c->w = c->h * c->w;
	}
	else
			return (0);
	return (1);
}

int		is_cam_info(char *line)
{
	if (ft_strequ("\torg[", line) || ft_strequ("\ttarget[\0", line))
		return (1);
	else if (ft_strequ("\tupguide[", line) || ft_strequ("\tfov[", line))
		return (1);
	else if (ft_strequ("\taspect_ratio[", line))
		return (1);
	return (0);
}

int		get_cam(int fd, t_cam *c)
{
	int		i;
	char	*line;

	i = 1;
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (i == 0)
			break ;
		if (line[0] == '\0')
			continue ;
		else if (ft_strequ("}\0", line))
		{
			ft_strdel(&line);
			return (1);
		}
		else if ((is_cam_info(line)))
		{
			if (!(get_cam_info(c, line)))
				break ;
		}
		else
			break ;
		ft_strdel(&line);
	}
	ft_strclr(line);
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
		if (i == 0)
			break ;
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
	return (1); // not sure about this, might not be valid
}