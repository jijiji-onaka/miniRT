/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:33:05 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 08:05:59 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cylinder.h"

void	cylinder_cap(t_p3 *a, t_cylinder *cy, char c)
{
	if (c == '+')
	{
		a->x = cy->pos.x + cy->nv.x * (cy->h / 2);
		a->y = cy->pos.y + cy->nv.y * (cy->h / 2);
		a->z = cy->pos.z + cy->nv.z * (cy->h / 2);
	}
	else if (c == '-')
	{
		a->x = cy->pos.x - cy->nv.x * (cy->h / 2);
		a->y = cy->pos.y - cy->nv.y * (cy->h / 2);
		a->z = cy->pos.z - cy->nv.z * (cy->h / 2);
	}
}

double	cylinder_inside(double a, double b,
		t_ray ray, t_cylinder *cy)
{
	double	res;
	t_p3	v[2];

	res = a;
	v[0] = intersect_point(ray, res);
	v[1] = substract_vec(v[0], cy->pos);
	if ((length_vec(v[1]) > fabs(cy->h / 2)))
		res = b;
	return (res);
}
