/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:39:25 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:51:43 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

char	*parse_ambient_light(char **p, t_ambient_light **a)
{
	char	*tmp;

	if (*a != NULL)
		return (ERR_AMBIENT);
	if (count_2d(p) != 2)
		return (ERR_RT_FORMAT3);
	if (!MALLOC(*a, 1))
		return (ERR_MALLOC);
	if (!ft_stod(p[0], &((*a)->ratio)) || !ft_stov(p[1], &((*a)->rgb)))
		return (ERR_RT_FORMAT2);
	if ((tmp = check_out_of_range((*a)->ratio, 0.0, 1.0,
			"[Ambient_light's ratio")))
		return (tmp);
	if ((tmp = check_vec_range((*a)->rgb, 0, 255, "[Ambient_light's color")))
		return (tmp);
	return (tmp);
}
