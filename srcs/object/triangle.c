/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:27:44 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:29:12 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/triangle.h"

static void	update_hit_point(t_hp *hp, t_triangle *tr, t_ray ray, double t)
{
	t_p3	tmp[2];

	hp->t = t;
	hp->p = intersect_point(ray, t);
	tmp[0] = substract_vec(tr->p2, tr->p1);
	tmp[1] = substract_vec(tr->p3, tr->p1);
	hp->nv = crossproduct(tmp[0], tmp[1]);
	normalize_vec(&(hp->nv));
	if (dotproduct(hp->nv, ray.d) > 0)
		hp->nv = scal_times_vec(hp->nv, -1);
	hp->rgb = tr->rgb;
	hp->dir_to_camera = scal_times_vec(ray.d, -1);
}

int			triangle_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_triangle	*tr;
	t_p3		v[5];
	double		n[4];
	double		t;

	hp->t = DBL_MAX;
	tr = (t_triangle *)obj;
	v[0] = substract_vec(tr->p2, tr->p1);
	v[1] = substract_vec(tr->p3, tr->p1);
	v[2] = crossproduct(ray.d, v[1]);
	if (fabs(n[0] = dotproduct(v[0], v[2])) < EPSILON)
		return (0);
	n[1] = 1.0 / n[0];
	v[3] = substract_vec(ray.o, tr->p1);
	n[2] = dotproduct(v[3], v[2]) * n[1];
	if (n[2] < EPSILON || n[2] > 1 + EPSILON)
		return (0);
	v[4] = crossproduct(v[3], v[0]);
	n[3] = dotproduct(ray.d, v[4]) * n[1];
	if (n[3] < EPSILON || n[2] + n[3] > 1 + EPSILON)
		return (0);
	if ((t = dotproduct(v[1], v[4]) * n[1]) < EPSILON)
		return (0);
	update_hit_point(hp, tr, ray, t);
	return (1);
}

char		*parse_triangle(char **p, void *obj)
{
	t_triangle	*new;
	char		*tmp;

	new = (t_triangle *)obj;
	if (count_2d(p) != 4)
		return (ERR_RT_FORMAT3);
	if (!ft_stov(p[0], &(new->p1)) ||
		!ft_stov(p[1], &(new->p2)) ||
		!ft_stov(p[2], &(new->p3)) ||
		!ft_stov(p[3], &(new->rgb)))
	{
		return (ERR_RT_FORMAT2);
	}
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Triangle color")))
		return (tmp);
	return (tmp);
}
