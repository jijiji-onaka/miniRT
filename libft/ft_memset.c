/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:17:40 by tjinichi          #+#    #+#             */
/*   Updated: 2020/06/29 02:21:16 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	unsigned char	chr;
	size_t			i;

	str = (unsigned char*)b;
	chr = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		str[i++] = chr;
	}
	return (b);
}
