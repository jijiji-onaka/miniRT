/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:47:25 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 16:49:08 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "../libft/libft.h"
# include "hit_point.h"

typedef struct		s_light
{
	t_p3			pos;
	double			ratio;
	t_p3			rgb;
	struct s_light	*next;
}					t_light;

char				*parse_light(char **p, t_light **llst);
void				clear_llst(t_light **llst);

#endif
