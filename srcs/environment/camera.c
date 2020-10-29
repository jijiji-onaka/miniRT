/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:51:06 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:51:58 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

t_camera	*now_camera(t_camera *clst, int current)
{
	int	i;

	i = 0;
	while (i < current)
	{
		clst = clst->next;
		i++;
	}
	return (clst);
}

int			clstsize(t_camera *clst)
{
	int len;

	len = 0;
	while (clst)
	{
		len++;
		clst = clst->next;
	}
	return (len);
}

void		clear_clst(t_camera **clst)
{
	if (*clst == NULL)
		return ;
	clear_clst(&((*clst)->next));
	free(*clst);
}

static void	clstadd_back(t_camera **clst, t_camera *new)
{
	if (!clst)
		return ;
	if (!*clst)
		*clst = new;
	else
		clstadd_back(&((*clst)->next), new);
}

char		*parse_camera(char **p, t_camera **clst)
{
	t_camera	*new;
	char		*tmp;

	if (count_2d(p) != 3)
		return (ERR_RT_FORMAT3);
	if (!MALLOC(new, 1))
		return (ERR_MALLOC);
	new->next = NULL;
	clstadd_back(clst, new);
	if (!ft_stov(p[0], &(new->pos)) ||
		!ft_stov(p[1], &(new->nv)) ||
		!ft_stoi(p[2], &(new->fov)))
	{
		return (ERR_RT_FORMAT2);
	}
	if ((tmp = check_vec_range(new->nv, -1.0, 1.0, "[Camera's vector")))
		return (tmp);
	if ((tmp = check_out_of_range(new->fov, 0, 180, "[Fov of camera")))
		return (tmp);
	if (fabs(length_vec(new->nv) - 0.0) < DBL_EPSILON)
		return (ERR_CAMERA_VEC);
	return (tmp);
}
