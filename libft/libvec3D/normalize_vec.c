/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:53:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 14:53:28 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	normalize_vec(t_p3 *p)
{
	double	mod;

	mod = sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
	p->x = p->x / mod;
	p->y = p->y / mod;
	p->z = p->z / mod;
}
