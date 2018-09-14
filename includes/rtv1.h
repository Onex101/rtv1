/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:21:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/14 13:58:58 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "lib_ray.h"
# include "lib_light.h"
# include "os.h"

# define WIDTH 640
# define HEIGHT 640
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
	t_vec3		tar;
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
	t_vector	*lis;
}				t_param;

int				key_press(int keycode, t_param *p);
void			init_cam(t_cam *cam, t_vec3 org, t_vec3 target, t_vec3 up, double fov, double aspect_ratio);
t_cam			*new_cam(t_vec3 org, t_vec3 target, t_vec3 up, double fov, double aspect_ratio);
t_ray			make_ray(t_cam *cam, t_vec3 pnt);
void			exit_program(t_param *p);
t_img			*new_image(void *mlx, int w, int h);
void			destroy_image(t_img *img, void *mlx);
int				init_param(t_param *p);
int 			ray_trace(t_param *p);
int				render(t_param *p);

#endif
