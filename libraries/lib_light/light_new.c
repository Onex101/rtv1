/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 07:44:33 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/28 07:33:29 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_light.h"

t_light		*light_new(t_vec3 dir, double intensity, t_colour col)
{
	t_light	*ret;

	if (!(ret = (t_light *)malloc(sizeof(t_light))))
		return (NULL);
	ret->dir = dir;
	ret->intensity = intensity;
	ret->col = col;
	return (ret);
}
