/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_inverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 17:49:09 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/18 13:53:59 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_mat.h"

double	determin(t_mat t, int k)
{
	double	deter = 0.0;
	double	z = 1.0;
	t_mat	rec;
	int a;
	int	b;
	int	c;
	int	x;
	int	y;

	if(k == 1)
	{
		return(t.mat[0][0]);
	}
	else
	{
		deter = 0;
		for (a = 0; a<k; ++a)
		{
			x = 0;
			y = 0;
			for (b=0; b<k; ++b)
			{
				for (c = 0; c < k; ++c)
				{
					rec.mat[b][c] = 0;
					if((b != 0) && (c != a))
					{
						rec.mat[x][y] = t.mat[b][c];
						if (y < (k-2))
							y++;
						else
						{
							y = 0;
							x++;
						}
					}
				}
			}
			deter = deter + z * (t.mat[0][a] * determin(rec, k-1));
			z *= -1;
		}
	}
	return(deter);
}

// This function is to find cofactors of matrix . . .
void cofac(t_mat comatr, int f)
{
	t_mat matr; 
	t_mat cofact;
	int a;
	int	b;
	int	c;
	int d;
	int	x;
	int	y;
	
	for(c = 0; c < f; ++c)
	{
		for(d = 0; d < f; ++d)
		{
			x=0;
			y=0;
			for (a = 0; a < f; ++a)
			{
				for(b = 0; b < f; ++b)
				{
					if(a != c && b != d)
					{
						matr.mat[x][y] = comatr.mat[a][b];
						if (y<(f-2))
							y++;
						else
						{
							y=0;
							x++;
						}
					}
				}
			}
			cofact.mat[c][d] = pow(-1, c + d) * determin(matr, f-1);
		}
	}
	trans(comatr, cofact, f);
}

// This function is to transpose of matrix . . .

void trans(t_mat matr, t_mat m1, int r)
{
	t_mat	inv_matrix;
	t_mat	tran;
 
	double	d;
	int		a;
	int		b;
	for(a=0;a<r;++a)
	{
		for(b=0;b<r;++b)
		{
			tran.mat[a][b] = m1.mat[b][a];
		}
	}
	d = determin(matr, r);
	for(a = 0; a < r; ++a)
	{
		for(b = 0; b < r; ++b)
		{
			inv_matrix.mat[a][b] = tran.mat[a][b] / d;
		}
	}
}

t_mat matrix_inverse(t_mat *mat)
{
	t_mat ret;
	double det;

	det = determin(mat, 4);

	return (ret);
}