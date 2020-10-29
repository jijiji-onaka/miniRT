/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:15:13 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:50:19 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_POINT_H
# define HIT_POINT_H

# include "../libft/libft.h"

typedef struct	s_hp
{
	double	t;
	t_p3	p;
	t_p3	nv;
	t_p3	rgb;
	t_p3	dir_to_camera;
}				t_hp;

double			solve_check(double a, double b, double epsilon);

#endif
