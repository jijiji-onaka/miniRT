/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:29:54 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 08:21:45 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include <limits.h>
# include "../libft/libft.h"
# include "hit_point.h"
# define MAX(x, y) (x > y ? x : y)
# define MIN(x, y) (x < y ? x : y)
# define MALLOC(p, n) ((p) = malloc(sizeof(*(p)) * (n)))
# define DEG_TO_RAD(deg) (deg * M_PI / 180)
# define RATIO(x, y) ((x) / (y))
# define EPSILON 1e-8
# define SP 0
# define PL 1
# define SQ 2
# define TR 3
# define CY 4
# define CU 5
# define PY 6

#endif
