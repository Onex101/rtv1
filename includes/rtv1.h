/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 09:21:31 by xrhoda            #+#    #+#             */
/*   Updated: 2018/09/28 07:55:19 by shillebr         ###   ########.fr       */
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
	void		*mlx;
	void		*win;
	t_img		*img;
	t_cam		*cam;
	t_vector	*set;
	t_vector	*lis;
}				t_param;

int     get_l_cols(t_light *shp, char *line, int i);
int     get_dir(t_light *lit, char *line, int i);
int		get_intensity(t_light *lit, char *line, int i);

int		get_radius(t_shape *shp, char *line, int i);
int     get_pos(t_shape *shp, char *line, int i);
int     get_cols(t_shape *shp, char *line, int i);
int		get_texture(t_shape *shp, char *line, int i);
int     get_norm(t_shape *shp, char *line, int i);
int     get_axis(t_shape *shp, char *line, int i);

void			exit_program(t_param *p);
int				key_press(int keycode, t_param *p);
int				ft_advance(char *str, int i);
int				ft_strcheck(const char *haystack, const char *needle);
int				get_double(double *d, char *line, int i);
void			assign_vec3(t_vec3 *v, char *line, int i, int count);
int				get_tvec3(t_vec3 *v, char *line, int i);
void			assign_col(t_colour *v, char *line, int i, int count);
int				get_tcol(t_colour *v, char *line, int i);
int				get_dir_light_info(t_light *lit, char *line);
int				make_dir_light(int fd, t_vector *set);
int				check_lights(int fd, t_vector *set, char *line);
int				is_lights(char *line);
int				read_lights(int fd, t_vector *set);
int				get_cam_info(t_cam *c, char *line);
int				is_cam_info(char *line);
int				read_camera(int fd, t_cam *cam);
int				get_cyl_info(t_shape *cyl, char *line);
int				make_cyl(int fd, t_vector *set);
int				get_cone_info(t_shape *cone, char *line);
int				make_cone(int fd, t_vector *set);
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
void			init_cam(t_cam *c, t_vec3 o, t_vec3 t, double f);
t_cam			*new_cam(t_vec3 org, t_vec3 target, double fov);
t_ray			make_ray(t_cam *cam, t_vec3 pnt);
int				cast_ray(t_vector *s, t_ray r);
t_img			*new_image(void *mlx, int w, int h);
void			destroy_image(t_img *img, void *mlx);
int				init_param(t_param *p);
int				ray_trace(t_param *p);
int				render(t_param *p);
t_colour		get_colour(t_param *p, t_inter *in, t_ray r);
t_colour		calc_light(t_light *l, t_param *p, t_inter *in, t_ray r);

#endif
