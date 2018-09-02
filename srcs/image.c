/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:28:49 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/02 11:05:26 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_img	*new_image(void *mlx, int w, int h)
{
	t_img *img;
	int		bpp;
	int		end;
	int		size_line;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->add = mlx_new_image(mlx, w, h)))
		return (NULL);
	img->buf = mlx_get_data_addr(img->add, &bpp, &size_line, &end);
	img->w = w;
	img->h = h;
	return (img);
}

void	destroy_image(t_img *img, void *mlx)
{
	if (img)
	{
		if (img->add)
			mlx_destroy_image(mlx, img->add);
		if (img->buf)
			free(img->buf);
		free(img);
	}
}