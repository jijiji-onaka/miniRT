/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:21:19 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/30 05:26:57 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "error.h"
# include "mlx.h"
# include "list_all.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <float.h>
# include <limits.h>

typedef struct		s_info
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	t_all			*all;
	int				f_save;
	int				fd;
}					t_info;

void				read_file(t_all	*all, char *filename);
void				ft_raytracing(t_info *info);
char				*minirt(char *filename, t_all *all, int f_save);
void				my_mlx_pixel_put(t_info *info, int x, int y, int color);

#endif
