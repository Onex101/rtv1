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
	printf("get cam info line [%s]\n", line);
	if (ft_strequ("\torg[\0", line))
	{
		ft_putendl("Entered org");
		if (!(get_tvec3(&c->org, line, 5)))
		{
			ft_putendl("org failed");
			return (0);
		}
		ft_putendl("org completed");

	}
	else if (ft_strequ(line, "\ttar["))
	{
		ft_putendl("Entered tar");
		if (!(get_tvec3(&c->tar, line, 4)))
		{
			ft_putendl("tar failed");
			return (0);
		}
		ft_putendl("org completed");
	}
	else if (ft_strequ(line, "\tup["))
	{
		ft_putendl("Entered up");
		if (!(get_tvec3(&c->up, line, 3)))
		{
			ft_putendl("up failed");
			return (0);
		}
		ft_putendl("up completed");
	}
	else if (ft_strequ(line, "\tfov["))
	{
		ft_putendl("Entered fov");
		if (!(get_double(&c->h, line, 4)))
		{
			ft_putendl("fov failed");
			return (0);
		}
		else
			c->h = tan(c->h);
		ft_putendl("fov completed");
	}
	else if (ft_strequ(line, "\taspect_ratio["))
	{
		ft_putendl("Entered aspect ratio");
		if (!(get_double(&c->w, line, 13)))
		{
			ft_putendl("aspect ratio failed");
			return (0);
		}
		else
			c->w = c->h * c->w;
		ft_putendl("aspect ratio completed");
	}
	else
	{
			ft_putendl("gci immediate failed");
			return (0);
	}
	return (1);
}

int		is_cam_info(char *line)
{
	if (ft_strequ("\torg[\0", line) || ft_strequ(line, "\ttar["))
		return (1);
	else if (ft_strequ(line, "\tup[") || ft_strequ(line, "\tfov["))
		return (1);
	else if (ft_strequ(line, "\taspect_ratio["))
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
		printf("get cam reading line: %s\n", line);
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		if (i != 0)
			printf("Get Cam Info Read: %s\n", line);
		if (line[0] == '\0')
			continue ;
		else if (ft_strequ(line, "}"))
		{
			ft_strdel(&line);
			return (1);
		}
		else if (!(is_cam_info(line)))
		{
			printf("is cam inf: %s\n", line);
			if (!(get_cam_info(c, line)))
			{
				printf("Get Cam Info Failed\n");
				break ;
			}
		}
		else
		{
			printf("get cam failed line: %s\n", line);
			break ;
		}
		printf("deleting line [%s]\n", line);
		ft_strdel(&line);
	}
	ft_strclr(line);
	ft_strdel(&line);
	return (0);
}

int		is_cam(char *line)
{
	ft_putendl("Is Camera test1");
	if (ft_strequ(line, "Camera{"))
		return (1);
	ft_putendl("Is Camera test2");
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
		ft_putendl("Camera test1");
		if ((i = get_next_line(fd, &line)) == 0)
			return (0);
		ft_putendl("Camera test2");		
		if (i == 0)
			break ;
		ft_putendl("Camera test3");		
		printf("Reading Cam: Line: %s\n", line);
		if (is_cam(line))
		{
            if (!(get_cam(fd, c)))
            {
				ft_putendl("Get Cam Fail");
				return (0);
			}
			ft_putendl("Get Cam success");

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