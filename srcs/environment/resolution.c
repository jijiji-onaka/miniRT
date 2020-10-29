/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 20:29:10 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:52:11 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/environment.h"

char	*parse_resolution(char **p, t_resolution **r)
{
	char	*tmp;

	if (*r != NULL)
		return (ERR_RESOLUTION);
	if (count_2d(p) != 2)
		return (ERR_RT_FORMAT3);
	if (!MALLOC(*r, 1))
		return (ERR_MALLOC);
	if (!ft_stoi(p[0], &((*r)->x)) || !ft_stoi(p[1], &((*r)->y)))
		return (ERR_RT_FORMAT2);
	if ((*r)->x == 0 || (*r)->y == 0)
		return (ERR_RESOLUTION3);
	if ((tmp = check_out_of_range((*r)->x, 0, INT_MAX, "[Render size of x")))
		return (tmp);
	if ((tmp = check_out_of_range((*r)->y, 0, INT_MAX, "[Render size of y")))
		return (tmp);
	return (tmp);
}
