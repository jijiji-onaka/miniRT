/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:26:52 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/25 18:28:23 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "../libft/libft.h"
# include "hit_point.h"
# include "error.h"
# include "screen.h"
# include "triangle.h"

typedef struct	s_square
{
	t_p3	pos;
	t_p3	nv;
	double	side;
	t_p3	rgb;
}				t_square;

char			*parse_square(char **p, void *obj);
int				square_intersect(void *obj, t_ray ray, t_hp *hp);

#endif
