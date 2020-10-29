/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stov.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:46:08 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 04:51:40 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stov(char *s, t_p3 *p)
{
	char	**a;
	int		ret;

	if (!(a = ft_split(s, ',')))
		return (0);
	ret = 0;
	if (count_2d(a) != 3)
	{
		array_free_2d(&a, count_2d(a));
		return (0);
	}
	if (!ft_stod(a[0], &(p->x)) ||
		!ft_stod(a[1], &(p->y)) ||
		!ft_stod(a[2], &(p->z)))
		ret = 1;
	array_free_2d(&a, count_2d(a));
	if (ret == 1)
		return (0);
	return (1);
}
