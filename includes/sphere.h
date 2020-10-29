/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:12:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 17:38:23 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "../libft/libft.h"
# include "hit_point.h"
# include "error.h"

typedef struct	s_sphere
{
	t_p3	pos;
	double	r;
	t_p3	rgb;
}				t_sphere;

char			*parse_sphere(char **p, void *obj);
int				sphere_intersect(void *obj, t_ray ray, t_hp *hp);

#endif
