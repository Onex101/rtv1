/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 07:27:29 by shillebr          #+#    #+#             */
/*   Updated: 2018/09/20 09:27:43 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		get_double(double *d, char *line, int i)
{
	if (is_num(line + i))
	{
		*d = ft_atoi(line + i);
		i = ft_advance(line, i);
	}
	else if (line[i] == ' ')
		i++;
	else if (line[i] == ']' && line[i + 1] == ';')
		return (1);
	else
		return (0);
}
