/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:57:44 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:04:35 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/screen.h"

t_p3		get_screen(t_screen screen, int j, int i, t_resolution *r)
{
	t_p3	res;

	res.x = -1 * screen.uvw[2].x + screen.viewport_width
		* screen.uvw[0].x / 2 + screen.viewport_height * screen.uvw[1].x / 2
		- screen.viewport_width * (j + 0.5) / r->x * screen.uvw[0].x
		- screen.viewport_height * (i + 0.5) / r->y * screen.uvw[1].x;
	res.y = -1 * screen.uvw[2].y + screen.viewport_width
		* screen.uvw[0].y / 2 + screen.viewport_height * screen.uvw[1].y / 2
		- screen.viewport_width * (j + 0.5) / r->x * screen.uvw[0].y
		- screen.viewport_height * (i + 0.5) / r->y * screen.uvw[1].y;
	res.z = -1 * screen.uvw[2].z + screen.viewport_width
		* screen.uvw[0].z / 2 + screen.viewport_height * screen.uvw[1].z / 2
		- screen.viewport_width * (j + 0.5) / r->x * screen.uvw[0].z
		- screen.viewport_height * (i + 0.5) / r->y * screen.uvw[1].z;
	return (res);
}

void		determine_axes(t_p3 uvw[3], t_p3 nv, double d)
{
	const t_p3	vup = {0, 1, 0};

	uvw[2] = scal_times_vec(nv, d);
	normalize_vec(&(uvw[2]));
	if (1.0 - fabs(dotproduct(uvw[2], vup)) < DBL_EPSILON)
		uvw[0] = new_vec(-1, 0, 0);
	else
		uvw[0] = crossproduct((t_p3)vup, uvw[2]);
	normalize_vec(&(uvw[0]));
	uvw[1] = crossproduct(uvw[2], uvw[0]);
}
