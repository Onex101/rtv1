/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_light.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 07:41:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 17:03:48 by shillebr         ###   ########.fr       */
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

t_light			*light_new(t_vec3 pos, double radius, t_colour col);

#endif
