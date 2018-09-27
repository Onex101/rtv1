/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_identity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:58:29 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 16:16:00 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

void	matrix_identity(t_mat *mat)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i == j)
				mat->mat[i][j] = 1;
			else
				mat->mat[i][j] = 0;
			j++;
		}
		i++;
	}
}
