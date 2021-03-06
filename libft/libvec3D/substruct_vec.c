/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substruct_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:52:37 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 14:52:49 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_p3	substract_vec(t_p3 minuend, t_p3 subtrahend)
{
	t_p3	res;

	res.x = minuend.x - subtrahend.x;
	res.y = minuend.y - subtrahend.y;
	res.z = minuend.z - subtrahend.z;
	return (res);
}
