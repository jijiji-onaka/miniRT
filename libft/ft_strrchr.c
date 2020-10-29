/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 13:16:02 by tjinichi          #+#    #+#             */
/*   Updated: 2020/07/02 12:46:49 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	size_t	len;

	chr = (char)c;
	len = ft_strlen((char*)s);
	if (chr == '\0')
		return ((char*)s + len);
	while (len)
	{
		len--;
		if (s[len] == chr)
		{
			return ((char*)s + len);
		}
	}
	return (NULL);
}
