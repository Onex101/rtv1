/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 07:41:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/13 08:06:06 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_LIGHT_H
# define LIB_LIGHT_H

# include "lib_vec.h"
# include "lib_col.h"

typedef struct	s_light
{
	t_vec3		dir;
	t_colour	col;
	double		intensity;
}				t_light;

#endif