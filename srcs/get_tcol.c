/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tcol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 12:14:30 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/25 17:44:01 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	assign_col(t_colour *v, char *line, int i, int count)
{
	if (count == 0)
		v->r = ft_atoi(line + i);
	else if (count == 1)
		v->g = ft_atoi(line + i);
	else if (count == 2)
		v->b = ft_atoi(line + i);
}

int		get_tcol(t_colour *v, char *line, int i)
{
	int	count;

	count = 0;
	while (line)
	{
		if (is_num(line + i))
		{
			if (count < 3)
				assign_col(v, line, i, count);
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
