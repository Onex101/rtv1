/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 13:11:58 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/29 18:31:30 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "lib_ft.h"
#include <stdio.h>

static	t_list	*new_file(t_list **file_list, int fd)
{
	t_list *tmp;

	tmp = *file_list;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", 1);
	tmp->content_size = fd;
	ft_lstadd(file_list, tmp);
	tmp = *file_list;
	return (tmp);
}

static	void	gnl_cat(char **line, t_list *file)
{
	int		size_line;
	char	*tmp;

	size_line = ft_strclen(file->content, '\n');
	*line = ft_strsub(file->content, 0, size_line);
	if (((char *)(file->content))[size_line] != '\0')
	{
		tmp = ft_strdup(file->content + (size_line + 1));
		free(file->content);
		file->content = tmp;
	}
	else
		ft_strclr(file->content);
}

static	int		gnl_read(char **line, t_list *file, char *buf)
{
	int		num_bytes;
	char	*tmp;

	while ((num_bytes = read(file->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[num_bytes] = '\0';
		if (!(tmp = ft_strjoin(file->content, buf)))
			return (-1);
		free(file->content);
		file->content = ft_strdup(tmp);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
		ft_strclr(buf);
	}
	if (num_bytes < BUFF_SIZE && !ft_strlen(file->content))
		return (0);
	gnl_cat(line, file);
	ft_strclr(buf);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static	t_list	*file_list;
	t_list			*file;
	int				i;

	if ((fd < 0 || !line || read(fd, 0, 0) < 0))
		return (-1);
	file = new_file(&file_list, fd);
	buf[BUFF_SIZE] = '\0';
	if ((i = gnl_read(line, file, buf)) == 0)
	{
		ft_strclr(file->content);
		return (0);
	}
	return (i);
}
