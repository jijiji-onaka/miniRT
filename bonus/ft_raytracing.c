/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 14:06:13 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 18:53:22 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/bmp.h"
#include "../includes/color.h"

static void	no_camera(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->all->r->y)
	{
		j = 0;
		while (j < info->all->r->x)
		{
			if (info->f_save)
				put_color_to_bmp(
					info->fd, rgb_to_color(0, 0, 0), info->all->r->x, j);
			else
				my_mlx_pixel_put(
					info, j, info->all->r->y - i - 1, rgb_to_color(0, 0, 0));
			j++;
		}
		i++;
	}
}

static void	create_image(t_info *info, t_camera *c, t_screen screen)
{
	int		y_i;
	int		x_i;
	t_ray	ray;

	y_i = 0;
	ray.o = c->pos;
	while (y_i < info->all->r->y)
	{
		x_i = 0;
		while (x_i < info->all->r->x)
		{
			ray.d = get_screen(screen, x_i, y_i, info->all->r);
			normalize_vec(&(ray.d));
			if (info->f_save)
				put_color_to_bmp(info->fd,
					get_color(info->all, ray), info->all->r->x, x_i);
			else
				my_mlx_pixel_put(
					info, x_i, info->all->r->y - y_i - 1,
					get_color(info->all, ray));
			x_i++;
		}
		y_i++;
	}
}

void		ft_raytracing(t_info *info)
{
	t_camera	*c;
	t_screen	screen;

	if (clstsize(info->all->clst) == 0)
		no_camera(info);
	else
	{
		c = now_camera(info->all->clst, info->all->current_c);
		screen.viewport_width = tan(DEG_TO_RAD(c->fov / 2)) * 2;
		screen.viewport_height = screen.viewport_width * \
			RATIO(info->all->r->y, info->all->r->x);
		determine_axes(screen.uvw, c->nv, -1.0);
		create_image(info, c, screen);
	}
	if (info->f_save)
		;
	else
		mlx_put_image_to_window(info->mlx_ptr, info->win_ptr,
		info->img_ptr, 0, 0);
}
