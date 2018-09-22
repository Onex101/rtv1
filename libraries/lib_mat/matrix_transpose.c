/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transpose.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:02:21 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/11 17:06:05 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

t_mat	matrix_transpose(t_mat *m)
{
	int i;
	int j;
	t_mat new;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			new.mat[i][j] = m->mat[j][i];
	}
	return (new);
}