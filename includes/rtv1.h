/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:21:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/08/30 14:13:41 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "lib_ray.h"

# define WIDTH 1280
# define HEIGHT 1024
# define RATIO WIDTH / HEIGHT

typedef struct	s_img
{
	void		*add;
	int			*buf;
	int			w;
	int			h;
}				t_img;

typedef struct	s_cam
{
	t_vec3		org;
	t_vec3		forward;
	t_vec3		up;
	t_vec3		right;
	double		h;
	double		w;
}				t_cam;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_cam		*cam;
	t_vector	*set;
}				t_param;

typedef struct	s_ray
{
	t_vec3		s_point; //starting point
	t_vec3		dir; //direction
}				t_ray;

#endif
