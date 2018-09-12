/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:15:14 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/12 18:57:12 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		read_class(int fd, t_vector *set, char *line)
{
	int		i;
	
	if (ft_strequ(line, "##Objects"))
	{
		if (!(read_objects(fd, set)))
			return (0);
	}
	else if (ft_strequ(line, "##Camera"))
	{
		if (!(read_cam(fd, set)))
			return (0);
	}
	else if (ft_strequ(line, "##Lights"))
	{
		if (!(read_light(fd, set)))
			return (0);
	}
	return (1); // not sure about this, might not be valid
}

int		ft_readfile(char *av, t_vector *set)
{
	char	*line;
	int		i;
	int		l;
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (0);
	i = 1;
	l = 0;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i == 0)
			break ;
		if (l == 0 && (!(ft_strequ(line, "##Scene"))))
			return (0);
		else if (!(read_class(fd, set, line)) && !(ft_strequ(line, "")))
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
	else if (ft_strlen(f_ext) == 4)
		return (1);
	return (0);
}