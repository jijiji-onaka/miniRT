/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:49:37 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 16:51:10 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_LIGHT_H
# define AMBIENT_LIGHT_H

# include "../libft/libft.h"
# include "hit_point.h"

typedef struct		s_ambient_light
{
	double	ratio;
	t_p3	rgb;
}					t_ambient_light;

char				*parse_ambient_light(char **p, t_ambient_light **a);

#endif
