/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 16:57:24 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 05:16:31 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/key_hook.h"

static void	free_mlx(t_info *info)
{
	if (!info)
		return ;
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	mlx_destroy_image(info->mlx_ptr, info->win_ptr);
}

int			exit_hook(t_info *info)
{
	free_all(info->all);
	exit(0);
}

int			key_hook(int keycode, t_info *info)
{
	int	c_num;
	int	*c_index;

	c_num = clstsize(info->all->clst);
	c_index = &(info->all->current_c);
	if (keycode == KEYCODE_ESC)
	{
		free_mlx(info);
		exit_hook(info);
	}
	else if (keycode == KEYCODE_LEFT && c_num > 0)
	{
		*c_index = (c_num + *c_index - 1) % c_num;
		ft_raytracing(info);
	}
	else if (keycode == KEYCODE_RIGHT && c_num > 0)
	{
		*c_index = (c_num + *c_index + 1) % c_num;
		ft_raytracing(info);
	}
	return (0);
}
