t_cone		*create_cone(t_vec3 p1, t_vec3 axis, double unit_radius,
				t_colour colour)
{
	t_cone	*cone;
	double	angle;
	t_mat4	mat;

	mat4_init(&mat);
	cone = f_memalloc(sizeof(t_cone));
	cone->origin = p1;
	cone->axis = vec3_normalize(axis);
	cone->radius = unit_radius;
	cone->colour = colour;
	cone->intersect = cone_intersect;
	angle = acos(vec3_dot(VEC3(0, 1, 0), axis) / vec3_length(axis));
	cone->imat = mat4_rotate(mat, -angle, vec3_cross(axis, VEC3(0, 1, 0)));
	cone->mat = mat4_inverse(cone->imat);
	return (cone);
}

static void	set_coef(t_ray ray, double radius, double coef[3])
{
	coef[0] = pow(ray.d.x, 2) + pow(ray.d.z, 2) - pow(ray.d.y * radius, 2);
	coef[1] = 2 * (ray.p.x * ray.d.x + ray.p.z * ray.d.z -
		ray.p.y * ray.d.y * pow(radius, 2));
	coef[2] = pow(ray.p.x, 2) + pow(ray.p.z, 2) - pow(ray.p.y * radius, 2);
}

bool		cone_intersect(void *shape, t_ray ray,
					t_intersect *intersect)
{
	t_cone		*cone;
	double		coef[3];
	double		t;
	double		des;

	intersect->ray = ray;
	intersect->shape = shape;
	cone = (t_cone*)shape;
	ray.p = vec3_transform(vec3_subtract(ray.p, cone->origin), cone->imat);
	ray.d = vec3_transform(ray.d, cone->imat);
	set_coef(ray, cone->radius, coef);
	des = f_quadratic_discriminant(coef[0], coef[1], coef[2]);
	if (des < RAY_T_MIN)
		return (false);
	t = (-coef[1] - sqrt(des)) / (2.0 * coef[0]);
	if (t > RAY_T_MIN && t < ray.t_max)
		intersect->t = t;
	else
		return (false);
	ray.p = vec3_normalize(ray_calculate(ray, t));
	intersect->normal = vec3_normalize(VEC3(ray.p.x, 0, ray.p.z));
	intersect->normal = vec3_normalize(VEC3(ray.p.x / cone->radius,
		(ray.p.y <= 0) ? cone->radius : -cone->radius,
		ray.p.z / cone->radius));
	return (true);
}

x = vec_sub(r->start, cone.pos);
	a = vec_dot(r->dir, cone.v);
	a = vec_dot(r->dir, r->dir) - (1 + cone.r * cone.r) * a * a;
	b = 2.0 * (vec_dot(r->dir, x) - (1 + cone.r * cone.r)
		* vec_dot(r->dir, cone.v) * vec_dot(x, cone.v));
	c = vec_dot(x, cone.v);
	c = vec_dot(x, x) - (1 + cone.r * cone.r) * c * c;