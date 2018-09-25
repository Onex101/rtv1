/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 15:11:16 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 15:12:13 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

Uint32	colour_to_int(t_colour col)
{
	Uint32			icol;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = col.r * 255;
	green = col.g * 255;
	blue = col.b * 255;
	icol = 0 | blue | (green << 8) | (red << 16);
	return (icol);
}