/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:52:10 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/10 22:24:23 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bmp.h"

static char	*make_extension(int idx, char *s)
{
	char	*res;
	size_t	i;
	size_t	len;

	len = ft_numlen(idx);
	if (!(res = malloc(sizeof(char) * (len + 7))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[len + i + 2] = s[i];
		i++;
	}
	i = len + 2 - (5 - i);
	res[len + 6] = '\0';
	res[0] = '[';
	res[i] = ']';
	while (idx != 0)
	{
		res[len] = idx % 10 + '0';
		idx /= 10;
		len--;
	}
	return (res);
}

static void	set_bmp_header(t_bitmapfileheader *header, int width, int height)
{
	int	zero_padding;

	if (width * 3 % 4 != 0)
		zero_padding = 4 - (width * 3 % 4);
	else
		zero_padding = 0;
	header->file_size = (width * 3 + zero_padding) * height;
	header->reserved[0] = 0;
	header->reserved[1] = 0;
	header->pixel_data_offset = 54;
}

static void	set_bmp_info(t_bitmapinfoheader *info, int width, int height)
{
	int	zero_padding;

	if (width * 3 % 4 != 0)
		zero_padding = 4 - (width * 3 % 4);
	else
		zero_padding = 0;
	info->header_size = sizeof(t_bitmapinfoheader);
	info->image_width = width;
	info->image_height = height;
	info->planes = 1;
	info->bits_per_pixel = 24;
	info->compression = 0;
	info->image_size = (width * 3 + zero_padding) * height;
	info->xpixels_per_meter = 2835;
	info->ypixels_per_meter = 2835;
	info->total_colors = 0;
	info->important_colors = 0;
}

int			open_bmp(char *file, int width, int height, int c_index)
{
	int					fd;
	unsigned short		file_type;
	char				*fn[2];
	t_bitmapfileheader	header;
	t_bitmapinfoheader	info;

	fn[0] = make_extension(c_index + 1, ".bmp");
	fn[1] = create_file_name("bmps", file, fn[0]);
	free(fn[0]);
	if (!fn[1])
		return (-1);
	fd = open(fn[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	free(fn[1]);
	if (fd < 0)
		return (fd);
	file_type = 0x4d42;
	set_bmp_header(&header, width, height);
	set_bmp_info(&info, width, height);
	write(fd, &file_type, sizeof(file_type));
	write(fd, &header, sizeof(header));
	write(fd, &info, sizeof(info));
	return (fd);
}

void		put_color_to_bmp(int fd, int color, int width, int x_i)
{
	const int zero = 0;

	write(fd, &color, 3);
	if (width - 1 == x_i && width * 3 % 4 != 0)
		write(fd, &zero, 4 - (width * 3 % 4));
}
