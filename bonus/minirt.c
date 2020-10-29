/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:52:09 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:15:52 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/bmp.h"
#include "../includes/key_hook.h"

void		my_mlx_pixel_put(t_info *info, int x, int y, int color)
{
	char	*dst;

	dst = info->addr + (y * info->size_line + x * (info->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static void	setup_mlx(t_info *info, char *fn)
{
	int		display_size[2];

	if (!(info->mlx_ptr = mlx_init()))
		free_all_and_exit_put(info->all, ERR_MLX);
	mlx_get_screen_size(info->mlx_ptr, &(display_size[0]), &(display_size[1]));
	if (info->all->r->x > display_size[0])
		info->all->r->x = display_size[0] - 30;
	if (info->all->r->y > display_size[0])
		info->all->r->y = display_size[0] - 50;
	if (!(info->win_ptr = mlx_new_window(
		info->mlx_ptr, info->all->r->x, info->all->r->y, fn)))
		free_all_and_exit_put(info->all, ERR_MLX_WIN);
	if (!(info->img_ptr = mlx_new_image(info->mlx_ptr, info->all->r->x,
		info->all->r->y)))
	{
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		free_all_and_exit_put(info->all, ERR_MLX_IMG);
	}
	info->addr = mlx_get_data_addr(info->img_ptr,
		&(info->bits_per_pixel), &(info->size_line), &(info->endian));
	mlx_key_hook(info->win_ptr, key_hook, info);
	mlx_hook(info->win_ptr, 17, 1L << 17, exit_hook, info);
}

static void	all_camera_to_bmp(t_info *info, char *filename)
{
	int		i;

	i = 0;
	while (i < clstsize(info->all->clst))
	{
		info->fd = open_bmp(filename, info->all->r->x, info->all->r->y, i);
		if (info->fd < 0)
		{
			free_all(info->all);
			exit_perror(ERR_BMP);
		}
		info->all->current_c = i;
		ft_raytracing(info);
		if (close(info->fd) < 0)
		{
			free_all(info->all);
			exit_perror(ERR_CLOSE);
		}
		i++;
	}
}

char		*minirt(char *filename, t_all *all, int f_save)
{
	t_info	info;

	info.all = all;
	info.f_save = f_save;
	if (f_save == 1)
	{
		all_camera_to_bmp(&info, filename);
	}
	else
	{
		setup_mlx(&info, filename);
		ft_raytracing(&info);
		mlx_loop(info.mlx_ptr);
	}
	return (NULL);
}
