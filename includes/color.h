/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 05:55:02 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/28 20:49:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "define.h"
# include "list_all.h"

int			rgb_to_color(int r, int g, int b);
int			get_color(t_all *all, t_ray ray);
t_p3		refraction_ray(t_ray ray, t_hp hp);

#endif
