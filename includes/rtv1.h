/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xrhoda <xrhoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:21:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/25 15:19:20 by xrhoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <unistd.h>
# include <stdlib.h>
// # include <mlx.h>
# include <SDL2/SDL.h>
# include <math.h>
# include <fcntl.h>
#include <stdbool.h> 
# include "lib_ray.h"
# include "lib_light.h"
# include "os.h"

# include <stdio.h>

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
	SDL_Window		*win;
	SDL_Surface		*srf;
	t_cam			*cam;
	t_vector		*set;
	t_vector		*lis;
}				t_param;

int				ft_advance(char *str, int i);
int				ft_strcheck(const char *haystack, const char *needle);

int				get_double(double *d, char *line, int i);
void			assign_vec3(t_vec3 *v, char *line, int i, int count);
int				get_tvec3(t_vec3 *v, char *line, int i);
void			assign_col(t_colour *v, char *line, int i, int count);
int				get_tcol(t_colour *v, char *line, int i);
Uint32			colour_to_int(t_colour col);
void			put_pixel(int x, int y, t_colour pixel, t_param *p);

int				get_dir_light_info(t_light *lit, char *line);
int				make_dir_light(int fd, t_vector *set);

int				check_lights(int fd, t_vector *set, char *line);
int				is_lights(char *line);
int				read_lights(int fd, t_vector *set);

int				read_camera(int fd, t_cam *cam);

int				get_plane_info(t_shape *plane, char *line);
int				make_plane(int fd, t_vector *set);

int				get_sphere_info(t_shape *sphere, char *line);
int				make_sphere(int fd, t_vector *set);

int				check_objects(int fd, t_vector *set, char *line);
int				is_obj(char *line);
int				read_objects(int fd, t_vector *set);

int				read_class(int fd, t_param *p, char *line);
int				read_file(char *av, t_param *p);
int				ft_rt(char *str);


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
