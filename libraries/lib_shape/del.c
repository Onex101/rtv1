t_cylinder	*create_cylinder(t_vec3 p1, t_vec3 axis, double radius,
				t_colour colour)
{
	t_cylinder	*cylinder;
	double		angle;
	t_mat4		mat;

	mat4_init(&mat);
	cylinder = f_memalloc(sizeof(t_cylinder));
	cylinder->origin = p1;
	cylinder->axis = vec3_normalize(axis);
	cylinder->radius = radius;
	cylinder->colour = colour;
	cylinder->intersect = cylinder_intersect;
	angle = acos(vec3_dot(VEC3(0, 1, 0), axis) / vec3_length(axis));
	cylinder->imat = mat4_rotate(mat, -angle, vec3_cross(axis, VEC3(0, 1, 0)));
	cylinder->mat = mat4_inverse(cylinder->imat);
	return (cylinder);
}

static void	set_coef(t_ray ray, double radius, double coef[3])
{
	coef[0] = pow(ray.d.x, 2) + pow(ray.d.z, 2);
	coef[1] = 2 * (ray.p.x * ray.d.x + ray.p.z * ray.d.z);
	coef[2] = pow(ray.p.x, 2) + pow(ray.p.z, 2) - pow(radius, 2);
}

bool		cylinder_intersect(void *shape, t_ray ray,
					t_intersect *intersect)
{
	t_cylinder	*cyl;
	double		coef[3];
	double		des;
	double		t;

	intersect->ray = ray;
	intersect->shape = shape;
	cyl = (t_cylinder*)shape;
	ray.p = vec3_transform(vec3_subtract(ray.p, cyl->origin), cyl->imat);
	ray.d = vec3_transform(ray.d, cyl->imat);
	set_coef(ray, cyl->radius, coef);
	des = f_quadratic_discriminant(coef[0], coef[1], coef[2]);
	if (des < RAY_T_MIN)
		return (false);
	t = (-coef[1] - sqrt(des)) / (2.0 * coef[0]);
	if (t > RAY_T_MIN && t < ray.t_max)
		intersect->t = fabs(t);
	else
		return (false);
	ray.p = ray_calculate(ray, t);
	ray.p = vec3_normalize(VEC3(ray.p.x, 0.0, ray.p.z));
	intersect->normal = vec3_transform(ray.p, cyl->mat);
	return (true);
}