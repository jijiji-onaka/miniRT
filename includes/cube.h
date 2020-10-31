/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:07:44 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 20:22:08 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "square.h"

char		*parse_cube(char **p, void *obj);
int			cube_intersect(void *obj, t_ray ray, t_hp *hp);

#endif
