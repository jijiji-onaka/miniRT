/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_all.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:10:53 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/25 18:27:43 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ALL_H
# define LIST_ALL_H

# include "resolution.h"
# include "ambient_light.h"
# include "light.h"
# include "camera.h"
# include "object.h"

typedef struct	s_all
{
	t_resolution	*r;
	t_ambient_light	*a;
	t_camera		*clst;
	t_light			*llst;
	t_objs_info		*olst;
	int				current_c;
}				t_all;

void			free_all(t_all *all);
void			free_all_and_exit_put(t_all *all, char *s);
void			read_file_error(int rc, t_all *all, char *s);

#endif
