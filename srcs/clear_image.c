/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:59:42 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 15:17:40 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	clear_image(t_img *p)
{
	int i;
	int j;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			if (p->buf[j * WIDTH + i] != 0x000000)
				p->buf[j * WIDTH + i] = 0x000000;
			i++;
		}
		j++;
	}
}
