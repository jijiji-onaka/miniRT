/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tail_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 04:04:44 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/26 04:05:52 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	file_tail_number(char *s)
{
	long long	res;
	int			f;

	f = 0;
	res = 0;
	while (*s && *s != ']')
	{
		if (f == 1)
			res = res * 10 + (*s - '0');
		if (*s == '[')
			f = 1;
		s++;
	}
	if (*s != ']')
		return (1);
	return (res + 1);
}
