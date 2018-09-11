/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:15:14 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/11 14:09:09 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_strcheck(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	int		crt;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	i = 0;
	crt = 0;
	while (*(haystack + i) && !crt)
	{
		if (*(haystack + i) == *(needle + 0))
		{
			j = 0;
			k = i;
			crt = 1;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					crt = 0;
			if (crt)
				return (1);
		}
		i++;
	}
	return (0);
}

int		get_transforms(t_shape *s, char *line)
{
	if (strcheck(line, "trans["))
	{
		if (!(get_trans(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "rot["))
	{
		if (!(get_rot(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "scale["))
	{
		if (!(get_colour(line, s)))
			ft_exit();
	}
}

int		read_sphere(t_shape *s, char *line)
{
	if (strcheck(line, "radius["))
	{
		if (!(get_radius(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "pos["))
	{
		if (!(get_pos(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "colour["))
	{
		if (!(get_colour(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "texture["))
	{
		if (!(get_texture(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "trans[") || strcheck(line, "rot[") || strcheck(line, "scale["))
	{
		if (!(get_transform(line, s)))
			ft_exit();
	}
	else if (strcheck(line, "}"))
		return (2);
	else
		return (0);
	return (1);
}

int		ft_make_sphere(int fd, t_vector *set)
{
	int		i;
	int		j;
	char	*line;

	i = 1;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0 && !(ft_strequ(line, "}")))
		{
			j = read_spere();
			if (j == 0)
				ft_exit();
			
		}
		else
			break ;
	}
}

int		ft_readfile(char *av, t_vector *set)
{
	char	*line;
	int		i;
	int		l;
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	i = 1;
	l = 0;
	while (i != 0)
	{
		i = get_next_line(fd, &line);
		if (i != 0)
		{
			if (l == 0 && (!(ft_strequ(line, "##Scene"))))
				return (0);
			else if (ft_strequ(line, "##Objects"))
				ft_putendl("Reading Objects");
			else if (ft_strequ(line, "Sphere"))
				ft_make_sphere(fd, set);//t_vector stores all the shapes, verctor add
			ft_strdel(&line);
		}
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