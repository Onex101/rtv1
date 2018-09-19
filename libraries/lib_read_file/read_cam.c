/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 08:18:24 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/19 13:56:55 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"


int		read_cam(int fd, t_cam *cam)
{
	char	*line;
	if (ft_strequ(line, "Org"))
	{
		cam->org.x = x;
		cam->org.y = y;
		cam->org.z = z;
	}
}