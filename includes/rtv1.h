/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:21:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/21 12:56:31 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 1024

typedef struct	s_img
{
	void		*add;
	int			*buf;
}				t_img;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_img		*img;
}				t_param;

#endif
