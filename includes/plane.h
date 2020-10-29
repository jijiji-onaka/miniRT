/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:17:58 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 17:38:25 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "../libft/libft.h"
# include "hit_point.h"
# include "error.h"

typedef struct	s_plane
{
	t_p3	pos;
	t_p3	nv;
	t_p3	rgb;
}				t_plane;

char			*parse_plane(char **p, void *obj);
int				plane_intersect(void *obj, t_ray ray, t_hp *hp);

#endif
