/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:22:26 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 08:06:12 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "../libft/libft.h"
# include "hit_point.h"
# include "error.h"
# include "disk.h"

typedef struct	s_cylinder
{
	t_p3	pos;
	t_p3	nv;
	double	r;
	double	h;
	t_p3	rgb;
}				t_cylinder;

char			*parse_cylinder(char **p, void *obj);
int				cylinder_intersect(void *obj, t_ray ray, t_hp *hp);
void			cylinder_cap(t_p3 *a, t_cylinder *cy, char c);
double			cylinder_inside(double a, double b,
				t_ray ray, t_cylinder *cy);

#endif
