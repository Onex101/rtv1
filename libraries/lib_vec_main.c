/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_vec_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:52:59 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/29 18:38:31 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"
#include "lib_ft.h"
#include "vector.h"
#include <stdio.h>

int main(void)
{
	t_vec3 v1;
	t_vec3 v2;

	v1 = vec3_new(1, 2, 3);
	v2 = (t_vec3){0, 0, 0};
	vec3_init(&v2, 1, 2, 3);
	vec3_mul(&(t_vec3){1, 2, 3}, 2);
	ft_putendl("Hello");
	printf("v1.x = [%f] | v2.x = [%f] | v1.y = [%f] | v2.y = [%f] | v1.z = [%f] | v2.z = [%f]\n", v1.x, v2.x, v1.y, v2.y, v1.z, v2.z);
	return (0);
}