/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 07:27:29 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/26 13:58:22 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_double(double *d, char *line, int i)
{
	if (line[i] == ' ')
		i++;
	if (is_num(line + i))
	{
		*d = ft_atod(line + i);
		i = ft_advance(line, i);
	}
	if (line[i] == ']' && line[i + 1] == ';')
		return (1);
	else
		return (0);
	return (0);
}
