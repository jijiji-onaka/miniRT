/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:28:17 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:52:49 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "../libft/libft.h"
# include "hit_point.h"
# include "error.h"

typedef struct	s_triangle
{
	t_p3	p1;
	t_p3	p2;
	t_p3	p3;
	t_p3	rgb;
}				t_triangle;

char			*parse_triangle(char **p, void *obj);
int				triangle_intersect(void *obj, t_ray ray, t_hp *hp);

#endif
