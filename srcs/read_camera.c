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

// int		get_cam_info(t_cam *c, char *line)
// {
// 	if (ft_strequ(line, "fov["))
// 		if (!(get_double(c->fov, line, 4)))
// 			return (0);
// 	else if (ft_strequ(line, "org["))
// 		if (!(get_tvec3(c->org, line, 4)))
// 			return (0);
// 	else if (ft_strequ(line, "target["))
// 		if (!(get_tvec3(c->tar, line, 7)))
// 			return (0);
//     else if (ft_strequ(line, "upguide["))
// 		if (!(get_tvec3(c->up, line, 8)))
// 			return (0);
// 	else if (ft_strequ(line, "aspect_ratio["))
// 		if (!(get_double(c->aspect_ratio, line, 13)))
// 			return (0);
// 	else
// 		return (0);
// 	return (1);
// }

// int		read_cam(int fd, t_cam *cam)
int		get_cam_info(t_cam *c, char *line)
{
	if (ft_strequ(line, "org["))
	{
		if (!(get_tvec3(&c->org, line, 4)))
			return (0);
	}
	else if (ft_strequ(line, "tar["))
	{
		if (!(get_tvec3(&c->tar, line, 4)))
			return (0);
	}
	else if (ft_strequ(line, "up["))
	{
		if (!(get_tvec3(&c->up, line, 3)))
			return (0);
	}
	else if (ft_strequ(line, "fov["))
	{
		if (!(get_double(&c->h, line, 4)))
			return (0);
		else
			c->h = tan(c->h);
	}
	else if (ft_strequ(line, "aspect_ratio["))
	{
		if (!(get_double(&c->w, line, 13)))
			return (0);
		else
			c->w = c->h * c->w;
	}
	else
		return (0);
	return (1);
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
		if (ft_strequ(line, ""))
			continue ;
		else if (ft_strequ(line, "}"))
		{
			ft_strdel(&line);
			return (1);
		}
		else if (!(get_cam_info(c, line)))
			break ;
		else
			break ;
		ft_strdel(&line);
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
	ft_putendl("Reading Camera");
	while (i != 0)
	{
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (is_cam(line))
		{
            if (!(get_cam(fd, c)))
                return (0);
        }
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
	return (1); // not sure about this, might not be valid
}