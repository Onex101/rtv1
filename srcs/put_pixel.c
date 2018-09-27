/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:59:29 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 13:39:46 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	check_endian(Uint8 *p, Uint32 pixel)
{
	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		p[0] = (pixel >> 16) & 0xff;
		p[1] = (pixel >> 8) & 0xff;
		p[2] = pixel & 0xff;
	}
	else
	{
		p[0] = pixel & 0xff;
		p[1] = (pixel >> 8) & 0xff;
		p[2] = (pixel >> 16) & 0xff;
	}
}

void		put_ipixel(int x, int y, Uint32 pixel)
{
	int		bpp;
	Uint8	*i;

	bpp = srf->format->BytesPerPixel;
	i = (Uint8 *)srf->pixels + y * srf->pitch + x * bpp;
	if (bpp == 1)
		*i = pixel;
	else if (bpp == 2)
		*(Uint16 *)i = pixel;
	else if (bpp == 3)
	{
		check_endian(i, pixel);
	}
	else if (bpp == 4)
		*(Uint32 *)i = pixel;
}

void		put_pixel(int x, int y, t_colour pixel)
{
	put_ipixel(x, y, colour_to_int(pixel));
}
