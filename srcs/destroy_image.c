/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 15:28:49 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 11:54:23 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	destroy_image(t_img *img, void *mlx)
{
	if (img)
	{
		if (img->add)
			// mlx_destroy_image(mlx, img->add);
		img->buf = NULL;
		free(mlx);
		free(img);
	}
}