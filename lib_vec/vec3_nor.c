/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_nor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:47:45 by xeno              #+#    #+#             */
/*   Updated: 2018/08/18 13:13:53 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"

double	vec3_nor(t_vec3 *v)
{
	double l;

	l = vec3_len(*v);
	vec3_div(v, l);
	return (l);
}

t_vec3	vec3_nor_cpy(t_vec3 v)
{
	t_vec3 cpy;

	cpy = vec3_cpy(v); 
	vec3_nor(&cpy);
	return(cpy);
}