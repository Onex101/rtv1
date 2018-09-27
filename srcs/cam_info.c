/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:54:24 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/27 14:55:07 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_cam_info(t_cam *c, char *line)
{
	if (ft_strequ("\torg[\0", line))
		return (!(get_tvec3(&c->org, line, 5))) ? (0) : (1);
	else if (ft_strequ("\ttarget[", line))
		return (!(get_tvec3(&c->tar, line, 8))) ? (0) : (1);
	else if (ft_strequ("\tupguide[", line))
		return (!(get_tvec3(&c->up, line, 9))) ? (0) : (1);
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
