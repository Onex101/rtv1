/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/07/17 08:35:35 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <stdlib.h>
# include "libft.h"

typedef struct	s_vector
{
	void		**items;
	double		capacity;
	double		total;
}				t_vector;

void			vector_init(t_vector *v);
int				vector_total(t_vector *v);
void			vector_resize(t_vector *v, int i);
void			vector_add(t_vector *v, void *pnt);
void			vector_set(t_vector *v, int i, void *ont);
void			*vector_get(t_vector *v, int i);
void			vector_delete(t_vector *v, int i);
void			vector_free(t_vector *v);

#endif
