/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:33:05 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/29 16:22:57 by tjinichi         ###   ########.fr       */
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
