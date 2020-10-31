/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 19:39:06 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 20:57:17 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/list_all.h"
#include "../includes/color.h"

int			rgb_to_color(int r, int g, int b)
{
	r = MAX(0, MIN(r, 255));
	g = MAX(0, MIN(g, 255));
	b = MAX(0, MIN(b, 255));
	return (r << 16 | g << 8 | b);
}

static int	closest_intersect(t_objs_info *olst, t_ray ray, t_hp *hp)
{
	t_hp	tmp;
	int		(*const each_intersect[])(void *, t_ray, t_hp *) = {
		sphere_intersect, plane_intersect, square_intersect,
		triangle_intersect, cylinder_intersect,
		cube_intersect,
	};

	hp->t = DBL_MAX;
	while (olst)
	{
		each_intersect[olst->type](&(olst->obj), ray, &tmp);
		if (tmp.t < hp->t)
			*hp = tmp;
		olst = olst->next;
	}
	if (hp->t < DBL_MAX)
		return (1);
	return (0);
}

static void	determine_color(t_p3 *rgb, t_light *l, t_hp hp, t_ray to_light)
{
	t_p3	reflect;

	rgb->x += hp.rgb.x * l->ratio * cos_vec(hp.nv, to_light.d);
	rgb->y += hp.rgb.y * l->ratio * cos_vec(hp.nv, to_light.d);
	rgb->z += hp.rgb.z * l->ratio * cos_vec(hp.nv, to_light.d);
	reflect.x = -1 * to_light.d.x + 2 * dotproduct(hp.nv, to_light.d) * hp.nv.x;
	reflect.y = -1 * to_light.d.y + 2 * dotproduct(hp.nv, to_light.d) * hp.nv.y;
	reflect.z = -1 * to_light.d.z + 2 * dotproduct(hp.nv, to_light.d) * hp.nv.z;
	rgb->x += l->ratio * l->rgb.x *
		pow(MAX(0, dotproduct(reflect, hp.dir_to_camera)), 16.0);
	rgb->y += l->ratio * l->rgb.y *
		pow(MAX(0, dotproduct(reflect, hp.dir_to_camera)), 16.0);
	rgb->z += l->ratio * l->rgb.z *
		pow(MAX(0, dotproduct(reflect, hp.dir_to_camera)), 16.0);
}

static void	add_ambient_light(t_p3 *rgb, t_ambient_light *a)
{
	rgb->x += a->ratio * a->rgb.x;
	rgb->y += a->ratio * a->rgb.y;
	rgb->z += a->ratio * a->rgb.z;
}

int			get_color(t_all *all, t_ray ray)
{
	t_p3	rgb;
	t_hp	hp[2];
	t_ray	to_light;
	t_light	*llst;

	rgb = new_vec(0, 0, 0);
	if (all->a != NULL)
		add_ambient_light(&rgb, all->a);
	if (!(closest_intersect(all->olst, ray, &(hp[0]))))
		return (rgb_to_color(255, rgb.y, rgb.z));
	to_light.o = hp[0].p;
	llst = all->llst;
	while (llst)
	{
		to_light.d = substract_vec(llst->pos, hp[0].p);
		normalize_vec(&(to_light.d));
		if (!closest_intersect(all->olst, to_light, &(hp[1])) ||
				length_vec(substract_vec(hp[0].p, llst->pos)) < hp[1].t)
			determine_color(&rgb, llst, hp[0], to_light);
		llst = llst->next;
	}
	return (rgb_to_color(rgb.x, rgb.y, rgb.z));
}
