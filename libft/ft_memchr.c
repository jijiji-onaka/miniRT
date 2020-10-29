/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:31:50 by tjinichi          #+#    #+#             */
/*   Updated: 2020/07/02 18:39:13 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;

	str = (unsigned char*)s;
	chr = (unsigned char)c;
	while (n > 0)
	{
		if (*str == chr)
		{
			return ((void*)str);
		}
		str++;
		n--;
	}
	return (NULL);
}
