/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:51:18 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 18:55:37 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/sphere.h"

/*
** https://www.scratchapixel.com/lessons/3d-basic-rendering
*/

static void		update_hit_point(t_hp *hp, t_sphere *sp, t_ray ray, double t)
{
	hp->t = t;
	hp->p = intersect_point(ray, t);
	hp->nv = substract_vec(hp->p, sp->pos);
	normalize_vec(&(hp->nv));
	if (dotproduct(hp->nv, ray.d) > 0)
		hp->nv = scal_times_vec(hp->nv, -1);
	hp->rgb = sp->rgb;
	hp->dir_to_camera = scal_times_vec(ray.d, -1);
}

static int		inside(t_p3 view_pos, t_sphere *sp)
{
	double a[3];
	double b[3];

	a[0] = sp->pos.x + sp->r;
	a[1] = sp->pos.y + sp->r;
	a[2] = sp->pos.z + sp->r;
	b[0] = sp->pos.x - sp->r;
	b[1] = sp->pos.y - sp->r;
	b[2] = sp->pos.z - sp->r;
	if (view_pos.x < b[0] || view_pos.x > a[0])
		return (0);
	if (view_pos.y < b[1] || view_pos.y > a[1])
		return (0);
	if (view_pos.z < b[2] || view_pos.z > a[2])
		return (0);
	return (1);
}

int				sphere_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_sphere	*sp;
	t_p3		l;
	double		n[4];
	double		t;

	hp->t = DBL_MAX;
	sp = (t_sphere *)obj;
	l = substract_vec(sp->pos, ray.o);
	n[0] = dotproduct(l, ray.d);
	if (inside(ray.o, sp) == 1)
	{
		l = scal_times_vec(l, -1);
		n[0] = dotproduct(l, ray.d) * -1;
	}
	else if (n[0] < 0)
		return (0);
	n[1] = dotproduct(l, l) - pow(n[0], 2.0);
	n[2] = pow(sp->r, 2.0);
	if (n[1] > n[2])
		return (0);
	n[3] = sqrt(n[2] - n[1]);
	if ((t = solve_check(n[0] - n[3], n[0] + n[3], EPSILON)) == EPSILON)
		return (0);
	update_hit_point(hp, sp, ray, t);
	return (1);
}

char			*parse_sphere(char **p, void *obj)
{
	t_sphere	*new;
	char		*tmp;

	new = (t_sphere *)obj;
	if (count_2d(p) != 3)
		return (ERR_RT_FORMAT3);
	if (!ft_stov(p[0], &(new->pos)) ||
		!ft_stod(p[1], &(new->r)) ||
		!ft_stov(p[2], &(new->rgb)))
	{
		return (ERR_RT_FORMAT2);
	}
	new->r /= 2;
	if ((tmp = check_out_of_range(new->r, 0.0, DBL_MAX, "[Sphere's radius")))
		return (tmp);
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Sphere color")))
		return (tmp);
	return (tmp);
}
