/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:29:30 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:43:40 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISK_H
# define DISK_H

# include "../libft/libft.h"
# include "hit_point.h"
# include "error.h"
# include "plane.h"

typedef struct	s_disk
{
	t_p3	pos;
	t_p3	nv;
	double	r;
	t_p3	rgb;
}				t_disk;

int				disk_intersect(void *obj, t_ray ray, t_hp *hp);

#endif
