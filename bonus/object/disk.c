/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:37:50 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:44:47 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/disk.h"

int		disk_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_disk	*di;
	t_plane	pl;
	t_hp	tmp;
	t_p3	v[2];

	hp->t = DBL_MAX;
	di = (t_disk *)obj;
	pl.pos = di->pos;
	pl.nv = di->nv;
	pl.rgb = di->rgb;
	if (!(plane_intersect(&pl, ray, &tmp)))
		return (0);
	v[0] = intersect_point(ray, tmp.t);
	v[1] = substract_vec(v[0], di->pos);
	if (length_vec(v[1]) > di->r)
		return (0);
	*hp = tmp;
	return (1);
}
