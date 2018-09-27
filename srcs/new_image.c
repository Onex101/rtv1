/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 09:07:53 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:10:23 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_img	*new_image(void *mlx, int w, int h)
{
	t_img	*img;
	int		bpp;
	int		end;
	int		size_line;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->add = mlx_new_image(mlx, w, h)))
		return (NULL);
	img->buf = (int *)mlx_get_data_addr(img->add, &bpp, &size_line, &end);
	img->w = w;
	img->h = h;
	return (img);
}
