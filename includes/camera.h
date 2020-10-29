/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:52:06 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 16:53:02 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "../libft/libft.h"
# include "hit_point.h"

typedef struct		s_camera
{
	t_p3			pos;
	t_p3			nv;
	int				fov;
	struct s_camera	*next;
}					t_camera;

char				*parse_camera(char **p, t_camera **clst);
void				clear_clst(t_camera **clst);
int					clstsize(t_camera *clst);
t_camera			*now_camera(t_camera *clst, int current);

#endif
