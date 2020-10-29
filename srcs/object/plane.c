/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:25:19 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:06:16 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/plane.h"

/*
** https://www.scratchapixel.com/lessons/
** 3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/
** ray-plane-and-ray-disk-intersection
*/

static void		update_hit_point(t_hp *hp, t_plane *pl, t_ray ray, double t)
{
	hp->t = t;
	hp->p = intersect_point(ray, t);
	hp->nv = pl->nv;
	if (dotproduct(hp->nv, ray.d) > 0)
		hp->nv = scal_times_vec(hp->nv, -1);
	hp->rgb = pl->rgb;
	hp->dir_to_camera = scal_times_vec(ray.d, -1);
}

int				plane_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_plane	*pl;
	double	denom;
	t_p3	p0l0;
	double	t;

	hp->t = DBL_MAX;
	pl = (t_plane *)obj;
	normalize_vec(&(pl->nv));
	denom = dotproduct(pl->nv, ray.d);
	if (fabs(denom) < 1e-6)
		return (0);
	p0l0 = substract_vec(pl->pos, ray.o);
	t = dotproduct(p0l0, pl->nv) / denom;
	if (t < EPSILON)
		return (0);
	update_hit_point(hp, pl, ray, t);
	return (1);
}

char			*parse_plane(char **p, void *obj)
{
	t_plane	*new;
	char	*tmp;

	new = (t_plane *)obj;
	if (count_2d(p) != 3)
		return (ERR_RT_FORMAT3);
	if (!ft_stov(p[0], &(new->pos)) ||
		!ft_stov(p[1], &(new->nv)) ||
		!ft_stov(p[2], &(new->rgb)))
	{
		return (ERR_RT_FORMAT2);
	}
	if ((tmp = check_vec_range(new->nv, -1.0, 1.0, "[Plane vector")))
		return (tmp);
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Plane color")))
		return (tmp);
	if (fabs(length_vec(new->nv) - 0.0) < DBL_EPSILON)
		return (ERR_PL_VEC);
	return (tmp = NULL);
}
