/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 00:24:19 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 04:18:48 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_bitmapfileheader
{
	unsigned int	file_size;
	unsigned short	reserved[2];
	unsigned int	pixel_data_offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfoheader
{
	unsigned int	header_size;
	int				image_width;
	int				image_height;
	unsigned short	planes;
	unsigned short	bits_per_pixel;
	unsigned int	compression;
	unsigned int	image_size;
	int				xpixels_per_meter;
	int				ypixels_per_meter;
	unsigned int	total_colors;
	unsigned int	important_colors;
}				t_bitmapinfoheader;

int				open_bmp(char *file, int width, int height, int c_index);
void			put_color_to_bmp(int fd, int color, int width, int x_i);

#endif
