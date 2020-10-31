/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:07:08 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 20:35:46 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube.h"

static void	init_cube(t_p3 nv[6])
{
	nv[0] = (t_p3) {1, 0, 0};
	nv[1] = (t_p3) {-1, 0, 0};
	nv[2] = (t_p3) {0, 1, 0};
	nv[3] = (t_p3) {0, -1, 0};
	nv[4] = (t_p3) {0, 0, 1};
	nv[5] = (t_p3) {0, 0, -1};
}

int			cube_intersect(void *obj, t_ray ray, t_hp *hp)
{
	t_square	*cu;
	t_square	sq;
	t_hp		tmp;
	t_p3		nv[6];
	int			i;

	hp->t = DBL_MAX;
	cu = (t_square *)obj;
	init_cube(nv);
	sq.rgb = cu->rgb;
	sq.side = cu->side;
	i = 0;
	while (i < 6)
	{
		sq.pos = add_vec(cu->pos,
							scal_times_vec(nv[i], cu->side / 2));
		sq.nv = nv[i];
		square_intersect(&sq, ray, &tmp);
		if (tmp.t < hp->t)
			*hp = tmp;
		i++;
	}
	if (hp->t < DBL_MAX)
		return (1);
	return (0);
}

char		*parse_cube(char **p, void *obj)
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
	if ((tmp = check_vec_range(new->nv, -1.0, 1.0, "[Cube's vector")))
		return (tmp);
	if ((tmp = check_out_of_range(new->side, 0.0, DBL_MAX, "[Cube's side")))
		return (tmp);
	if ((tmp = check_vec_range(new->rgb, 0, 255, "[Cube's color")))
		return (tmp);
	if (fabs(length_vec(new->nv) - 0.0) < DBL_EPSILON)
		return (ERR_CU_VEC);
	return (tmp);
}
