/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:15:44 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/26 10:48:48 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_new(void)
{
	t_vector *v;

	v = (t_vector *)malloc(sizeof(t_vector));
	vector_init(v);
	return (v);
}
