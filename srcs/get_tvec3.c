/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tvec3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:59:10 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/26 13:58:30 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	assign_vec3(t_vec3 *v, char *line, int i, int count)
{
	if (count == 0)
		v->x = ft_atod(line + i);
	else if (count == 1)
		v->y = ft_atod(line + i);
	else if (count == 2)
		v->z = ft_atod(line + i);
}

int		get_tvec3(t_vec3 *v, char *line, int i)
{
	int	count;

	count = 0;
	while (line)
	{
		if (is_num(line + i))
		{
			if (count < 3)
				assign_vec3(v, line, i, count);
			else
				return (0);
			count++;
			i = ft_advance(line, i);
		}
		else if (line[i] == ',' || line[i] == ' ')
			i++;
		else if (line[i] == ']' && line[i + 1] == ';' && count == 3)
			return (1);
		else
			return (0);
	}
	return (0);
}
