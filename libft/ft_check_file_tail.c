/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_tail.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:28:05 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/16 16:40:54 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			check_file_tail(char *s, char *tail)
{
	char	*tmp;
	size_t	tail_len;

	tail_len = ft_strlen(tail);
	tmp = ft_substr(s, ft_strlen(s) - tail_len, tail_len);
	if (ft_strncmp(tmp, tail, tail_len) == 0)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
