/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/27 06:26:00 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/27 19:03:34 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>
# include "lib_ft.h"

typedef struct	s_vector
{
	void		**items;
	int			capacity;
	int			total;
}				t_vector;

void			vector_init(t_vector *v);
int				vector_total(t_vector *v);
void			vector_resize(t_vector *v, int i);
void			vector_add(t_vector *v, void *pnt);
void			vector_set(t_vector *v, int i, void *ont);
void			*vector_get(t_vector *v, int i);
void			vector_delete(t_vector *v, int i);
void			vector_free(t_vector *v);
t_vector		*vector_new(void);

#endif
