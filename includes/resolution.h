/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:39:45 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 16:40:39 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RESOLUTION_H
# define RESOLUTION_H

typedef struct		s_resolution
{
	int		x;
	int		y;
}					t_resolution;

char				*parse_resolution(char **p, t_resolution **r);

#endif
