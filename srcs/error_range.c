/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 19:22:29 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:03:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error.h"
#include "../includes/list_all.h"

char	*check_vec_range(t_p3 v, double min, double max, char *s)
{
	char	*res;

	if ((res = check_out_of_range(v.x, min, max, s)))
		return (res);
	if ((res = check_out_of_range(v.y, min, max, s)))
		return (res);
	if ((res = check_out_of_range(v.z, min, max, s)))
		return (res);
	return (res);
}
