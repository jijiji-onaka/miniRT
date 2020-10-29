/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 05:33:48 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:36:06 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hit_point.h"
#include "../includes/define.h"

double	solve_check(double a, double b, double epsilon)
{
	if (a < epsilon && b < epsilon)
		return (epsilon);
	else if (a < epsilon)
		return (b);
	else if (b < epsilon)
		return (a);
	else
		return (MIN(a, b));
}
