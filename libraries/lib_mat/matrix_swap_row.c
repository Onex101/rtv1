/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_swap_row.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:12:43 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:07:30 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

void	matrix_swap_row(t_mat *m, int i, int j)
{
	int		k;
	double	tmp;

	k = -1;
	while (++k < 4)
	{
		tmp = m->mat[i][k];
		m->mat[i][k] = m->mat[j][k];
		m->mat[j][k] = tmp;
	}
}
