/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:31:11 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:52:45 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "sphere.h"
# include "plane.h"
# include "square.h"
# include "triangle.h"
# include "cylinder.h"
# include "disk.h"
# include <stdlib.h>

typedef struct			s_objs
{
	t_sphere	sp;
	t_plane		pl;
	t_square	sq;
	t_cylinder	cy;
	t_triangle	tr;
}						t_objs;

typedef struct			s_objs_info
{
	t_objs				obj;
	t_p3				color;
	t_p3				nv;
	int					type;
	struct s_objs_info	*next;
}						t_objs_info;

void					clear_olst(t_objs_info **olst);
void					olstadd_back(t_objs_info **olst, t_objs_info *new);

#endif
