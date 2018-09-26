/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:15:14 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/26 14:12:59 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		read_class(int fd, t_param **p, char *line)
{
	if (ft_strequ(line, "##Objects"))
	{
		if (!(read_objects(fd, &(*p)->set)))
			return (0);
	}
	else if (ft_strequ(line, "##Camera"))
	{
		if (!(read_camera(fd, (*p)->cam)))
			return (0);
	}
	else if (ft_strequ(line, "##Lights"))
	{
		if (!(read_lights(fd, (*p)->lis)))
			return (0);
	}
	return (1); // not sure about this, might not be valid
}

int		read_file(char *av, t_param **p)
{
	char	*line;
	int		i;
	int		l;
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	i = 1;
	l = 0;
	if (!p)
		return (0);
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i == 0)
			break ;
		if (ft_strequ("##Scene", line))
		{
			if (l != 0)
				return (0);
		}
		else if (l > 0 && line[0] == '\0')
		{
			ft_strdel(&line);
			continue ;
		}
		else if (!(read_class(fd, p, line)))
			return (0);
		ft_strdel(&line);
		l++;
	}
	return (1);
}

int		ft_rt(char *str)
{
	char *f_ext;

	f_ext = ft_strstr(str, ".rt");
	if (!f_ext)
		return (0);
	else if (ft_strlen(f_ext) == 3)
		return (1);
	return (0);
}