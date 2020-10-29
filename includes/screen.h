/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:58:46 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/25 18:22:23 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "../libft/libft.h"
# include "resolution.h"
# include "define.h"

typedef struct	s_screen
{
	double	viewport_width;
	double	viewport_height;
	t_p3	uvw[3];
}				t_screen;

t_p3			get_screen(t_screen screen, int j, int i, t_resolution *r);
void			determine_axes(t_p3 uvw[3], t_p3 nv, double d);

#endif
