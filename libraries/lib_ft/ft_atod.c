/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:46:01 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 13:47:33 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft.h"
#include <stdio.h>

double	ft_atod(char *str)
{
	char	**splt;
	double	start;
	double	end;
	int		len;

	start = 0;
	if (str)
	{
		splt = ft_strsplit(str, '.');
		start = (double)ft_atoi(splt[0]);
		end = 0;
		if (splt[1])
		{
			len = ft_strlen(splt[1]) - 3;
			while (len >= 0)
				end = end / 10 + (splt[1][len--] - 48);
			end /= 10;
		}
		if (start >= 0)
			start += end;
		else
			start -= end;
	}
	return (start);
}
