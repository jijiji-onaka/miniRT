/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:33:05 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/10 20:50:17 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cylinder.h"

static void	update_hit_point(t_hp *hp, t_cylinder *cy, t_ray ray, double t)
{
	t_p3	v;

	hp->t = t;
	hp->p = intersect_point(ray, t);
	v = substract_vec(hp->p, cy->pos);
	hp->nv.x = v.x - dotproduct(v, cy->nv) * cy->nv.x;
	hp->nv.y = v.y - dotproduct(v, cy->nv) * cy->nv.y;
	hp->nv.z = v.z - dotproduct(v, cy->nv) * cy->nv.z;
	normalize_vec(&(hp->nv));
	if (dotproduct(hp->nv, ray.d) > 0)
		hp->nv = scal_times_vec(hp->nv, -1);
	hp->rgb = cy->rgb;
	if (inside_cy(ray.o, cy) == 1)
		hp->dir_to_camera = scal_times_vec(ray.d, 1);
	else
		hp->dir_to_camera = scal_times_vec(ray.d, -1);
}

static int	infinite_cylinder(t_cylinder *cy, t_ray ray, t_hp *hp)
{
	t_p3	v[5];
	double	n[4];
	double	t[3];

	hp->t = DBL_MAX;
	normalize_vec(&(cy->nv));
	v[0] = substract_vec(ray.o, cy->pos);
	v[1] = substract_vec(ray.d,
			scal_times_vec(cy->nv, dotproduct(ray.d, cy->nv)));
	v[2] = substract_vec(v[0],
			scal_times_vec(cy->nv, dotproduct(v[0], cy->nv)));
	n[0] = dotproduct(v[1], v[1]);
	n[1] = 2 * dotproduct(v[1], v[2]);
	n[2] = dotproduct(v[2], v[2]) - pow(cy->r, 2.0);
	if (fabs(n[3] = pow(n[1], 2.0) - 4 * n[0] * n[2]) < 0.001 || n[3] < 0)
		return (0);
	t[1] = (-1 * n[1] - sqrt(n[3])) / (2 * n[0]);
	t[2] = (-1 * n[1] + sqrt(n[3])) / (2 * n[0]);
	if (t[1] < EPSILON && t[2] < EPSILON)
		return (0);
	t[0] = cylinder_inside(t[1], t[2], ray, cy);
	update_hit_point(hp, cy, ray, t[0]);
	return (1);
}

static int	cylinder_body(t_cylinder *cy, t_ray ray, t_hp *hp)
{
	t_hp	tmp;
	t_p3	v[3];

	hp->t = DBL_MAX;
	normalize_vec(&(cy->nv));
	if (!infinite_cylinder(cy, ray, &tmp))
		return (0);
	cylinder_cap(&(v[0]), cy, '+');
	cylinder_cap(&(v[1]), cy, '-');
	v[2] = intersect_point(ray, tmp.t);
	if (dotproduct(cy->nv, substract_vec(v[2], v[0])) *
		dotproduct(cy->nv, substract_vec(v[2], v[1])) > 0)
		return (0);
	*hp = tmp;
	return (1);
}

int			cylinder_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_cylinder	*cy;
	t_hp		tmp;

	hp->t = DBL_MAX;
	cy = (t_cylinder *)obj;
	cylinder_body(cy, ray, &tmp);
	if (tmp.t < hp->t)
		*hp = tmp;
	return (hp->t < DBL_MAX);
}

char		*parse_cylinder(char **p, void *obj)
{
	t_cylinder	*new;
	char		*tmp;

	new = (t_cylinder *)obj;
	if (count_2d(p) != 5)
		return (ERR_RT_FORMAT3);
	if (!ft_stov(p[0], &(new->pos)) ||
		!ft_stov(p[1], &(new->nv)) ||
		!ft_stod(p[2], &(new->r)) ||
		!ft_stod(p[3], &(new->h)) ||
		!ft_stov(p[4], &(new->rgb)))
		return (ERR_RT_FORMAT2);
	if ((tmp = check_vec_range(new->nv, -1.0, 1.0, "[Cylinder's vector")))
		return (tmp);
	if ((tmp = check_out_of_range(new->r, 0, DBL_MAX, "[Cylinder's diameter")))
		return (tmp);
	if ((tmp = check_out_of_range(new->h, 0.0, DBL_MAX, "[Cylinder's height")))
		return (tmp);
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Cylinder color")))
		return (tmp);
	new->r /= 2;
	if (fabs(length_vec(new->nv) - 0.0) < DBL_EPSILON)
		return (ERR_CY_VEC);
	normalize_vec(&(new->nv));
	return (tmp);
}
