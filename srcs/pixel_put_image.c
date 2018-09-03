/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:59:29 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/03 14:01:37 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	pixel_put_image(t_img *img, int x, int y, int c)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		if (WIDTH * y + x < WIDTH * HEIGHT && WIDTH * y + x >= 0)
			img->buf[WIDTH * y + x] = c;
	}
	else
		return ;
}
