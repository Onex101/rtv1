/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_nor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeno <xeno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:47:45 by xeno              #+#    #+#             */
/*   Updated: 2018/08/16 18:02:07 by xeno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3_lib.h"

void	vec3_nor(t_vec3 *v)
{
	if (v)
		(vec3_div(v, vec3_len(v)));
}

t_vec3 *vec3_nor_cpy(t_vec3 *v)
{
	t_vec3 *cpy;

	if (v)
	{
		if(!(cpy = vec3_cpy(v)))
			return (NULL);
		vec3_nor(cpy);
		return(cpy);
	}
	return (NULL);
}