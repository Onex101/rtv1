/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 07:44:33 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/13 08:00:52 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_light.h"

t_light		light_new(t_vec3 dir, double intensity, t_colour col)
{
	t_light	ret;

	ret.dir = dir;
	ret.intensity = intensity;
	ret.col = col;
	return (ret);
}