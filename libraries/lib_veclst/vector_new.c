/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:15:44 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 09:01:53 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vector_new(void)
{
	t_vector *v;

	if (!(v = (t_vector *)malloc(sizeof(t_vector))))
		return (NULL);
	vector_init(v);
	return (v);
}
