/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:26:56 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:30:05 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/square.h"

static void	sq_to_2tr(t_triangle *tr, t_square *sq, t_screen s)
{
	tr->p1.x = sq->pos.x + s.uvw[0].x * (sq->side / 2) +
							s.uvw[1].x * (sq->side / 2);
	tr->p1.y = sq->pos.y + s.uvw[0].y * (sq->side / 2) +
							s.uvw[1].y * (sq->side / 2);
	tr->p1.z = sq->pos.z + s.uvw[0].z * (sq->side / 2) +
							s.uvw[1].z * (sq->side / 2);
	tr->p2.x = tr->p1.x - s.uvw[0].x * sq->side;
	tr->p2.y = tr->p1.y - s.uvw[0].y * sq->side;
	tr->p2.z = tr->p1.z - s.uvw[0].z * sq->side;
	tr->p3.x = tr->p1.x - s.uvw[1].x * sq->side;
	tr->p3.y = tr->p1.y - s.uvw[1].y * sq->side;
	tr->p3.z = tr->p1.z - s.uvw[1].z * sq->side;
}

int			square_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_square	*sq;
	t_triangle	tr;
	t_screen	screen;
	t_hp		tmp;

	hp->t = DBL_MAX;
	sq = (t_square *)obj;
	normalize_vec(&(sq->nv));
	determine_axes(screen.uvw, sq->nv, 1.0);
	sq_to_2tr(&tr, sq, screen);
	tr.rgb = sq->rgb;
	triangle_intersect(&tr, ray, &tmp);
	if (tmp.t < hp->t)
		*hp = tmp;
	tr.p1.x -= (screen.uvw[0].x + screen.uvw[1].x) * sq->side;
	tr.p1.y -= (screen.uvw[0].y + screen.uvw[1].y) * sq->side;
	tr.p1.z -= (screen.uvw[0].z + screen.uvw[1].z) * sq->side;
	triangle_intersect(&tr, ray, &tmp);
	if (tmp.t < hp->t)
		*hp = tmp;
	return (hp->t < DBL_MAX);
}

char		*parse_square(char **p, void *obj)
{
	t_square	*new;
	char		*tmp;

	new = (t_square *)obj;
	if (count_2d(p) != 4)
		return (ERR_RT_FORMAT3);
	if (!ft_stov(p[0], &(new->pos)) ||
		!ft_stov(p[1], &(new->nv)) ||
		!ft_stod(p[2], &(new->side)) ||
		!ft_stov(p[3], &(new->rgb)))
	{
		return (ERR_RT_FORMAT2);
	}
	if ((tmp = check_vec_range(new->nv, -1.0, 1.0, "[Square vector")))
		return (tmp);
	if ((tmp = check_out_of_range(new->side, 0.0, DBL_MAX, "[Square's side")))
		return (tmp);
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Square color")))
		return (tmp);
	if (fabs(length_vec(new->nv) - 0.0) < DBL_EPSILON)
		return (ERR_SQ_VEC);
	return (tmp);
}
